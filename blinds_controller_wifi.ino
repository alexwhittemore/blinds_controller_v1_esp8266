/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * WARNING! ESP8266 SSL support is still experimental.
 *          More info here: https://github.com/esp8266/Arduino/issues/43
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "TOKEN";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "SSID", "PASSWORD");

  // Make sure the digital pins are low to start, rather than sending the Arduino into a frenzy.
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
}

// If blynk sends V1, open to midway
BLYNK_WRITE(V1){
  int pinData = param.asInt();
  digitalWrite(D2, pinData);
  Serial.print("Got sig V1, sending D2 val: ");Serial.println(pinData);
}

/*
BLYNK_WRITE(V2){
  Serial.println("Got sig V2");
}
*/

void loop()
{
  Blynk.run();
}

