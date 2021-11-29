/* Arduino */
#include <Arduino.h>
#include <ESP8266WiFi.h>

/* Airly */
#include <airly/Thing.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  beginThing();

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() { updateThing(); }
