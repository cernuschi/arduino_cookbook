/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Arduino MKR 1010
  to connect your project to Blynk.

  Note: This requires WiFiNINA library
    from http://librarymanager/all#WiFiNINA

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "tokrn";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "retw wifi";
char pass[] = "password wifi";

BlynkTimer timer;

void setup() {  
  pinMode(5, INPUT);  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); 
  timer.setInterval(300L, leggibt ); 
}

void loop() {
  Blynk.run();
  timer.run();
}

void leggibt() {
  if (digitalRead(5)) {
    Blynk.virtualWrite(V10, 255); 
    Serial.println("BT");
  } else {
    Blynk.virtualWrite(V10, 0);
  }  
}
