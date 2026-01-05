# Wiring Diagram

### Components:
- **ESP32** (Powered via USB or 5V Vin)
- **Touch Sensor (TTP223):**
  - SIG: GPIO 4
  - VCC: 3.3V / 5V
  - GND: GND

### Outputs:
- **Relay (Strip Control):** GPIO 23
- **Laser Diode:** GPIO 22
- **Passive Buzzer:** GPIO 17

### Lights:
- **NeoPixel Ring (24 LEDs):**
  - Data: GPIO 21
  - VCC: 5V 
  - GND: GND
- **RGB LED:**
  - Red Pin: GPIO 19
  - Green Pin: GPIO 18
  - Blue Pin: GPIO 5
  - GND: GND
- **LED strips:**
  - 5V: COM (Relay) ---> 5V external (NO on relay)
  - GND: GND
  
