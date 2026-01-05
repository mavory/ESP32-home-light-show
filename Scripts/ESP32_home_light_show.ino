#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_NeoPixel.h>
#include <LittleFS.h>
//PINOUT!!!!!!
#define PIN_RELAY 23
#define PIN_LASER 22
#define PIN_RING  21
#define PIN_BUZZ  17
#define PIN_TOUCH 4
#define PIN_L_R   19
#define PIN_L_G   18
#define PIN_L_B   5
#define NUM_LEDS  24

Adafruit_NeoPixel ring(NUM_LEDS, PIN_RING, NEO_GRB + NEO_KHZ800);
AsyncWebServer server(80);//WEB SERVER

bool sysOn = false; //jestli je systen on na bootu
int currentMode = 1;
bool hwRelay = true, hwLaser = true, hwRing = true, hwBuzz = true;

const int chBuzz = 0;

void setStatusLED(int r, int g, int b) {
  digitalWrite(PIN_L_R, r);
  digitalWrite(PIN_L_G, g);
  digitalWrite(PIN_L_B, b);
}

void killBuzzer() {
  ledcWrite(chBuzz, 0);
  ledcDetachPin(PIN_BUZZ);
  pinMode(PIN_BUZZ, OUTPUT);
  digitalWrite(PIN_BUZZ, LOW);
}

void reattachBuzzer() {
  ledcSetup(chBuzz, 2000, 8);
  ledcAttachPin(PIN_BUZZ, chBuzz);
}

void stopAll() {
  killBuzzer();
  digitalWrite(PIN_RELAY, LOW);
  digitalWrite(PIN_LASER, LOW);
  ring.clear();
  ring.show();
}

void ringEffect(int type, uint32_t color, int speed, int bright) {
  if(!hwRing || !sysOn || bright == 0) { ring.clear(); ring.show(); return; }
  ring.setBrightness(bright);
  unsigned long ms = millis();
  int s = (speed < 20) ? 20 : speed;
  int pos = (ms / (s/4)) % NUM_LEDS;

  switch(type) {
    case 0: for(int i=0; i<NUM_LEDS; i++) ring.setPixelColor(i, color); break;
    case 1: ring.clear(); for(int i=0; i<6; i++) ring.setPixelColor((pos+i)%NUM_LEDS, color); break;
    case 2: for(int i=0; i<NUM_LEDS; i++) ring.setPixelColor(i, ring.ColorHSV((ms/4 + i*2730) % 65536, 255, 255)); break;
    case 3: 
      { // Přidány závorky pro vyřešení chyby "jump to case label", prostě to strašný bug
        ring.clear(); 
        int b = ( (ms/s) % (NUM_LEDS*2) < NUM_LEDS ) ? (ms/s)%NUM_LEDS : (NUM_LEDS*2 - (ms/s)%NUM_LEDS - 1); 
        ring.setPixelColor(b, color); 
      } 
      break;
    case 4: if(random(10)>7) ring.setPixelColor(random(NUM_LEDS), color); else ring.clear(); break;
  }
  ring.show();
}

void playSound(int type, int vol, int speed) {
  if(!hwBuzz || type == 0 || vol == 0 || !sysOn) { ledcWrite(chBuzz, 0); return; }
  unsigned long ms = millis();
  int freq = 0; bool on = false;
  switch(type) {
    case 1: if(ms % 1000 < 150) { freq = 2000; on = true; } break;
    case 2: freq = 800 + (sin(ms * 0.007) * 400); on = true; break;
    case 3: if(ms % speed < (speed/2)) { freq = 1000; on = true; } break;
    case 4: if(random(100) < 15) { freq = random(300, 2000); on = true; } break;
    case 5: if(ms % 100 < 50) { freq = 3000; on = true; } break;
  }
  if(on) { ledcWriteTone(chBuzz, freq); ledcWrite(chBuzz, vol); } else ledcWrite(chBuzz, 0);
}
//toto je web, prostě zase ta šibenice moje
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html><html><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
<style>
  body { background:#000; color:#fff; font-family:sans-serif; margin:0; padding:10px; }
  .panel { background:#0a0a0a; border:1px solid #222; padding:15px; border-radius:12px; max-width:500px; margin:auto; }
  .grid { display:grid; grid-template-columns:repeat(2, 1fr); gap:10px; margin-bottom:20px; }
  button { background:#151515; border:1px solid #333; color:#fff; padding:15px 5px; border-radius:8px; cursor:pointer; font-size:12px; font-weight:bold; }
  .act { background:#fff !important; color:#000 !important; }
  .pwr { width:100%; padding:20px; font-size:16px; margin-bottom:20px; border:2px solid #fff; border-radius:10px; font-weight:bold; background:none; color:#fff; }
  .poff { border-color:#f44; color:#f44; }
  .hw-grid { display:grid; grid-template-columns:repeat(4, 1fr); gap:5px; margin-top:20px; }
  .hw-grid button { font-size:9px; padding:10px 2px; }
</style></head><body>

<div class="panel">
  <button id="pwr" class="pwr" onclick="req('/t-sys')">SYSTEM LOADING...</button>
  
  <div class="grid">
    <button id="m1" onclick="req('/mode?v=1')">FOREST</button><button id="m2" onclick="req('/mode?v=2')">CYBER</button>
    <button id="m3" onclick="req('/mode?v=3')">NUCLEAR</button><button id="m4" onclick="req('/mode?v=4')">SUNSET</button>
    <button id="m5" onclick="req('/mode?v=5')">AMBIENT</button><button id="m6" onclick="req('/mode?v=6')">FOCUS</button>
    <button id="m7" onclick="req('/mode?v=7')">DISCO</button><button id="m8" onclick="req('/mode?v=8')">STROBE</button>
    <button id="m9" onclick="req('/mode?v=9')">POLICE</button><button id="m10" onclick="req('/mode?v=10')">EXTREME</button>
  </div>

  <div class="hw-grid">
    <button id="hwR" onclick="req('/hw?w=r')">STRIP</button><button id="hwL" onclick="req('/hw?w=l')">LASER</button>
    <button id="hwRi" onclick="req('/hw?w=ri')">RING</button><button id="hwB" onclick="req('/hw?w=b')">BUZZ</button>
  </div>
</div>

<script>
async function req(u){ await fetch('/api'+u); update(); }
async function update(){
  const r = await fetch('/api/stat'); const d = await r.json();
  const p=document.getElementById('pwr'); 
  p.className=d.on?'pwr':'pwr poff'; 
  p.innerText=d.on?'SYSTEM ONLINE':'SYSTEM OFFLINE';
  for(let i=1;i<=10;i++){ let b=document.getElementById('m'+i); b.className=d.m==i?'act':''; }
  document.getElementById('hwR').className=d.hr?'act':'';
  document.getElementById('hwL').className=d.hl?'act':'';
  document.getElementById('hwRi').className=d.hri?'act':'';
  document.getElementById('hwB').className=d.hb?'act':'';
}
setInterval(update, 2000); update();
</script></body></html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAY, OUTPUT); pinMode(PIN_LASER, OUTPUT);
  pinMode(PIN_L_R, OUTPUT); pinMode(PIN_L_G, OUTPUT); pinMode(PIN_L_B, OUTPUT);
  pinMode(PIN_TOUCH, INPUT);
  
  reattachBuzzer();
  ring.begin(); ring.show();
  WiFi.begin("WIFI", "PASSWORD"); //HERE IS WIFI PASSWORD!!!!!!!!!

  server.on("/api/stat", HTTP_GET, [](AsyncWebServerRequest *r){
    String j="{ \"on\":"+String(sysOn)+",\"m\":"+String(currentMode)+",\"hr\":"+String(hwRelay)+",\"hl\":"+String(hwLaser)+",\"hri\":"+String(hwRing)+",\"hb\":"+String(hwBuzz)+"}";
    r->send(200, "application/json", j);
  });

  server.on("/api/t-sys", HTTP_GET, [](AsyncWebServerRequest *r){ sysOn=!sysOn; stopAll(); if(sysOn) reattachBuzzer(); r->send(200); });
  
  server.on("/api/mode", HTTP_GET, [](AsyncWebServerRequest *r){ 
    currentMode=r->getParam("v")->value().toInt(); 
    stopAll(); reattachBuzzer(); r->send(200); 
  });

  server.on("/api/hw", HTTP_GET, [](AsyncWebServerRequest *r){ 
    String w=r->getParam("w")->value(); 
    if(w=="r")hwRelay=!hwRelay; if(w=="l")hwLaser=!hwLaser; 
    if(w=="ri")hwRing=!hwRing; if(w=="b")hwBuzz=!hwBuzz;
    stopAll(); reattachBuzzer(); r->send(200); 
  });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *r){ r->send_P(200, "text/html", index_html); });
  server.begin();
}

void loop() {
  static bool lastTouch = false;
  bool touch = digitalRead(PIN_TOUCH);
  if(touch && !lastTouch) {
    sysOn = !sysOn; stopAll(); if(sysOn) reattachBuzzer();
    delay(300);
  }
  lastTouch = touch;

  if(!sysOn) { setStatusLED(1,0,0); stopAll(); return; }
  else setStatusLED(0,1,0);

  unsigned long now = millis();
  int f = 127 + 127*sin(now/800.0);
//ty mody, který jsou epicky
  switch(currentMode) {
    case 1: if(hwRelay) digitalWrite(PIN_RELAY, 1); ringEffect(0,0x00FF00,0,150); break;
    case 2: if(hwLaser) digitalWrite(PIN_LASER, 1); ringEffect(0,0xFF00FF,0,200); break;
    case 3: if(hwRelay && now%1000<500) digitalWrite(PIN_RELAY, 1); else digitalWrite(PIN_RELAY,0); ringEffect(0,0xFF6000,0,200); playSound(3,150,600); break;
    case 4: if(hwRelay) digitalWrite(PIN_RELAY, 1); ringEffect(0,ring.Color(255,f/2,0),0,f); break;
    case 5: if(hwRelay) digitalWrite(PIN_RELAY, 1); ringEffect(0,0xFFFFFF,0,150); break;
    case 6: if(hwRelay) digitalWrite(PIN_RELAY, 1); ringEffect(0,0x0000FF,0,f); break;
    case 7: if(hwRelay && now%400<200) digitalWrite(PIN_RELAY,1); else digitalWrite(PIN_RELAY,0); if(hwLaser && now%200<100) digitalWrite(PIN_LASER,1); else digitalWrite(PIN_LASER,0); ringEffect(2,0,50,200); playSound(3,180,400); break;
    case 8: if(now%120<60){ if(hwRelay) digitalWrite(PIN_RELAY,1); ringEffect(0,0xFFFFFF,0,255); } else { digitalWrite(PIN_RELAY,0); ring.clear(); } playSound(5,255,0); break;
    case 9: if(now%600<300){ ringEffect(0,0xFF0000,0,255); } else { ringEffect(0,0x0000FF,0,255); } playSound(2,180,0); break;
    case 10: if(random(10)>7 && hwRelay) digitalWrite(PIN_RELAY,1); else digitalWrite(PIN_RELAY,0); if(random(10)>6 && hwLaser) digitalWrite(PIN_LASER,1); else digitalWrite(PIN_LASER,0); ringEffect(4,ring.Color(random(255),random(255),random(255)),50,255); playSound(4,220,0); break;
  }
}

//@MAVORY WAS HERE
