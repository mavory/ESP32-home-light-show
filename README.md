# ESP32 home light show

Using ESP32 you can make a small home light show with 2 LED strips, a neopixel ring, a laser, a buzzer and an RGB LED!

## Why did I do this?

I wanted to create something with lighting effects and a few days ago I got this ring, so I wanted to try it out and also see how the relay works with LED strips.

## Features

- Web interface
- You can switch modes
- It has a buzzer and an RGB LED for notification
- You can turn off various lights, buzzer, etc.

## Scripts

The script has exactly 199 lines, so it fit under 200!! It was very difficult, but I put everything in just one script, so you can just copy it and paste it into the ESP32 right away.

## How it works?

You can change profiles and turn off various lights via the web. The web runs on the ESP32 IP address. There is a small RGB LED and a buzzer for signaling. Everything can be turned on manually using the touch sensor hidden in the case.

- **Mode 1 (FOREST):** Constant green ring light with strip.
- **Mode 2 (CYBER):** Constant magenta ring light with laser.
- **Mode 3 (NUCLEAR):** Blinking relay with orange ring and pulsing warning buzzer.
- **Mode 4 (SUNSET):** Breathing effect on the ring in sunset colors.
- **Mode 5 (AMBIENT):** White ring light and relay for steady "illumination".
- **Mode 6 (FOCUS):** Blue pulsing ring effect for concentration with active relay.
- **Mode 7 (DISCO):** Strobe for relay and laser with rainbow ring and rhythmic beeps.
- **Mode 8 (STROBE):** High speed white strobe and ring with buzzer.
- **Mode 9 (POLICE):** Red and blue flashing ring with a siren sound.
- **Mode 10 (EXTREME):** Random chaotic flashing with flickering colors and noise.

**_I like sunset the most and extreme is probably the most chaotic!_**

### Home page:
![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4NTksInB1ciI6ImJsb2JfaWQifX0=--70971a166bda32901f76a24320f7783428571bb9/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

## 3D models

Here is a view of the top and bottom of the case:

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4OTAsInB1ciI6ImJsb2JfaWQifX0=--22fc92f969a296d73315411b6e9bb9b59c3d9cf7/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzM4OTUsInB1ciI6ImJsb2JfaWQifX0=--89f68f30199aad29996fbc9abb73c9edfc49b0e7/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJwbmciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--0f85faa91c373105a0f317054e965c1f47e93a37/image.png)

## There is the final video of how it works!

_Here is a youtube video where you can see how it works:_ [Link](https://www.youtube.com/watch?v=FMIBLFgBRWg)

![image](https://blueprint.hackclub.com/user-attachments/representations/redirect/eyJfcmFpbHMiOnsiZGF0YSI6NzQxNTMsInB1ciI6ImJsb2JfaWQifX0=--d712cbdc21cf348626c334a65f3a5a4c1fc1d5da/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJqcGciLCJyZXNpemVfdG9fbGltaXQiOlsyMDAwLDIwMDBdLCJjb252ZXJ0Ijoid2VicCIsInNhdmVyIjp7InF1YWxpdHkiOjgwLCJzdHJpcCI6dHJ1ZX19LCJwdXIiOiJ2YXJpYXRpb24ifX0=--15ca3815f01a5683e19ea0585d2eef9af9e441d7/IMG_20260105_200620.jpg)
