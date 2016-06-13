# blinds_controller_wifi
This is the component of the project to run on on an ESP8266, interfacing with Blynk.cc

## Hardware
The hardware consists of a NodeMCU ESP8266 dev board, in my case a Version 1.0 (ESP-12E) board. Presumably it should be trivial to use something else.

Three GPIO pins are used to signal the Arduino component, "Down" on D3 (GP0 in the Blynk app), "Mid" on D2 (GP4) and "High" on D1 (GP5). My blinds take 9 full rotatins to go full down to full up, so Down is 0 rotations, Mid is 4.5, and High is 9.

These three pins are wired to Arduino pins 8/9/10 for down, mid, and up. That is, D3-8, D2-9, D1-10.

## Mobile Software
I've used the Blynk app for this iteration of the project, in my case running on my iOS phone. Two buttons are set in switch mode on GP2 and GP16, corresponding to the onboard LEDs, mostly for debug and sanity check. Buttons for Down, Mid, and Up are also present on GP0, GP4, and GP5. Additionally, a timer is wired to V1, which in this code actuates GP4, triggering the "Mid" condition (open). This timer is used to open the blinds at 5:30am.

## Notes on startup
The Blynk library seems not to assert the state of pins at start until you actuate them in-app. My MO so far has been to plug in my hardware stack holding the Arduino reset button, until I can load the app, wait for the ESP8266 to connect, and let the arduino boot with all pins properly low. I've just included a fix to assert low during startup, but I haven't actually tested it. Try that if things go haywire on startup.