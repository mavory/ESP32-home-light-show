# My Journal

This is a Journal where I describe everything about this project.

## So how much time did I spend on that?

I spent about 20 hours on this project.

## My worst hangups

- I guess.. I did the case wrong, so I had to redo it.
- I couldn't solve one bug for a long time, so it kept me very busy.
- Several times, the cables fell out of my breadboard, so I forgot where they were supposed to be connected.

## Timeline

### The beginning of an idea!
After my last project I decided to make a new one - a home light show. I was thinking about what I could do with the things I have at home and how:

The website would control everything and I could also set a scheduler, when and for how long to turn the whole system on/off.
2x LED strips that would be connected via a relay and directly to the socket
​​1x neopixel ring that would give that effect to it!
1x RGB LED that would signal the modes
1x buzzer so I could have a response
1x laser to add even more atmosphere
1x touch sensor that would allow everything to be controlled offline

I would like to make the website minimalistic and black and white, everything would run on the ESP32 IP address!

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzIxODgsInB1ciI6ImJsb2JfaWQifX0=--985d9848693f768c9e2dd85572993e8a3743f4c2/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/20260104_175004.jpg)

### Soldering cables
I was thinking about how to connect the strips to the relay and I decided to use only one, because I only have one... I put an external 5V into the COM and connected the power supply to the strips to the other one, so when it connects, the strip will light up.
But I had to solder everything and also connect everything to the jumpers first, so that everything holds well, so I took some electrical tape and wrapped it around it, because I know from before that it falls a lot, so that I could avoid that now.

Jumpers:

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzIzMzIsInB1ciI6ImJsb2JfaWQifX0=--2e90c4f3c874b94e26e00acb4a89088ad31bf8e9/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/20260104_185737.jpg)

When I had it, as I mentioned, I started soldering, first I tinned each wire and later started soldering it together. I also added a jumper to GND to connect it to the ESP32. Later I wrapped everything with tape again and went to connect it, but I still didn't know how to connect it to the breadboard.

Soldering:

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzIzMzMsInB1ciI6ImJsb2JfaWQifX0=--f48657005eae34cfac1a5fb903e6fb8cce52b23b/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/20260104_184013.jpg)

### Connecting jumpers
I managed to connect the jumpers pretty quickly and thus I was able to move on to the code! That will probably be harder, but I'll try it.
The biggest problem for me was probably the ring, because I never connected it, but I managed to do it, so it's good now.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzIzOTcsInB1ciI6ImJsb2JfaWQifX0=--c7eb05c2a4fd19ff84b313afa595de21d2e48391/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/20260104_192444.jpg)

### My first coding
I started coding, I thought it would work, but when I finished the first code, the touch button stopped working.
I made a new code with a new website, but the strips stopped working again, my solution was to connect the GND strip externally and it started working, here you can see the first attempt of the website:

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzI0MDgsInB1ciI6ImJsb2JfaWQifX0=--ea4385393c006eb22907ac61a71656561c01ed42/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

### Continuing coding!!
I told myself that I would also add user profiles so I could create my own, I also implemented flashing into the strips so they would flash and I fixed the laser that was previously on and sometimes off, I also added the ability to turn different things on and off independently.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzI1MjUsInB1ciI6ImJsb2JfaWQifX0=--218fb2c190e865e919eba5e6988fc13186719469/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/Sn%C3%ADmek%20obrazovky%202026-01-04%20205950.png)

### Another website update
I wasn't happy with my website, so I put everything on the widescreen, but some things aren't working yet, but about 80% of it is. I managed to do a lot of work today and I'll continue tomorrow.

I made the system more modern and minimalistic. I added some control buttons
I modified the editor for my own profiles, where I made new buttons for presets
I also tried to make a scheduler, but unfortunately it doesn't work yet, because it doesn't turn itself off yet.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzI2MTUsInB1ciI6ImJsb2JfaWQifX0=--c9d64755a56950403fd81e9d874ab62f3ff2f4e1/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

### Making a case for ESP32!
So today I overcame myself and started making designs for a 3D case, I tried different things, but then I still ended up making a larger case and putting a lid on top, which will hold all the things, there is a hole on the side for the LED strips, because those will have the case itself, which I will create later.
On the back of the case there will be power for the ESP32 and on the top there will be holes for the ring, LED,...
It took me a while today, but I think I did a good job.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzI3NjUsInB1ciI6ImJsb2JfaWQifX0=--4a1fe1f50bb37dd729e9f1b8100df984b5719838/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/Screenshot_20260104_225806_Chrome.jpg)

### Rewriting broken code
I'm continuing with the website, unfortunately I've been coding for over 2 hours today and I still can't find the problem with the profile editor.
I probably have a long way to go, but so far I've completely redone the profile files, which I think are awesome! The buttons now work on and off. Now I'm going to start 3D printing the case and later I'll make the upper part for the case, which I still have to model.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4NDAsInB1ciI6ImJsb2JfaWQifX0=--c0fc62c8521eb0ee552dab9ab11f79c56828e851/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

### Error solved
I tried for about an hour, but unfortunately I couldn't figure out how to fix this error, so I removed it all, unfortunately. I focused on the code with the preset profiles and modified them.
For now, I have the code ready and now I'm going to start making the upper part of the case. Here is the description of the profiles:

Mode 1 (FOREST): Constant green ring light with strip.
Mode 2 (CYBER): Constant magenta ring light with laser.
Mode 3 (NUCLEAR): Blinking relay with orange ring and pulsing warning buzzer.
Mode 4 (SUNSET): Breathing effect on the ring in sunset colors.
Mode 5 (AMBIENT): White ring light and relay for steady "illumination".
Mode 6 (FOCUS): Blue pulsing ring effect for concentration with active relay.
Mode 7 (DISCO): Strobe for relay and laser with rainbow ring and rhythmic beeps.
Mode 8 (STROBE): High speed white strobe and ring with buzzer.
Mode 9 (POLICE): Red and blue flashing ring with a siren sound.
Mode 10 (EXTREME): Random chaotic flashing with flickering colors and noise.
I like sunset the most and extreme is probably the most chaotic!

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4NTksInB1ciI6ImJsb2JfaWQifX0=--70971a166bda32901f76a24320f7783428571bb9/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

### Finishing the 3D models!!
I think this is done. Hopefully everything will fit... I measured everything and made holes for everything.
There is a hole for the ESP32 power supply at the back and another for the LED strips.
The strips will be led away on the side.
At the top in the middle there is a hole for the laser and above that there is a hole exactly for the ring, which will be placed there later. On the right I made a holder for the touch sensor, which probably took me the most time! Then I added a hole for the LED and connected everything together. I rendered everything and it was done.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4OTAsInB1ciI6ImJsb2JfaWQifX0=--22fc92f969a296d73315411b6e9bb9b59c3d9cf7/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4OTUsInB1ciI6ImJsb2JfaWQifX0=--89f68f30199aad29996fbc9abb73c9edfc49b0e7/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

### 3D Case Remake
Ahhh... Unfortunately I modeled the top part badly. So it took away my precious time to redo it again. All the holes are too small, I thought the values ​​would be good, but I was wrong. I also made a low slider for the touch sensor, so I redid all of that.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzQwMTEsInB1ciI6ImJsb2JfaWQifX0=--e9aabd9efd21366bdf60312599a23af08eeb72a7/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/20260105_180834.jpg)

### Circuit Diagram is ready
I tried to create a circuit diagram in KiCad, I used ESP32 again, buzzer, RGB LED,... I connected everything, but before that I was wondering if there were different models for some components in my project - I couldn't find anything after research, so I used generic connectors.
After connecting and exporting, I remembered that I could add how I would connect the 5V strips to the relay, so I finished that and I think that it should be all from KiCad.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzQxMDAsInB1ciI6ImJsb2JfaWQifX0=--851178d54ed1b3e2f80226b502ffb29c2f320760/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

### Finishing the case
I decided to make the case first and then finish GitHub. I started by putting the breadboard with the components in the case and as always (it's a ritual) the cables fall out, so I don't know where to connect them...
But when I solved this, another problem came up, I couldn't get to the relay very well, but I somehow managed to connect the LED strips. The holes for the things were already big enough and everything went smoothly. I later glued the ring so that it wouldn't move.
I also had to remove the supports from the 3D print, then I closed and glued everything together!

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzQxNDAsInB1ciI6ImJsb2JfaWQifX0=--58dc7b73a43266ffa7e8bfddfda8f799802874be/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/20260105_195151.jpg)

### Finishing the smaller details
I still had to finish some minor details. I had to peel off the ring and stick it back on and tape it from the bottom. I also wrapped the cable with white tape and closed everything again later.

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzQxNTMsInB1ciI6ImJsb2JfaWQifX0=--d712cbdc21cf348626c334a65f3a5a4c1fc1d5da/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/IMG_20260105_200620.jpg)

### GitHub editing

When I had the case finished, I spent some time working on **GitHub**. I had to export all the **stuff** and later **upload it** to the aforementioned GitHub:
- BOM
- Journal.md
- Readme.md
- CAD (3D models)
- Scripts (.ino script)
- Circuit diagram (Info.md ​​and CD)
- Photos

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzQyNTYsInB1ciI6ImJsb2JfaWQifX0=--7bce5bc3861346372c1963c0615a452fb0d23ee3/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

