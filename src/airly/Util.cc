#include <airly/Util.h>

/* Arduino */
#include <ESP8266WiFi.h>

String getMacAddressWithoutColon() {
  auto macAddress = WiFi.macAddress();
  macAddress.replace(":", "");
  return macAddress;
}
