#include <airly/Thing.h>

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* Arduino */
#include <Arduino.h>
#include <ESP8266WiFi.h>

/* WebThings framework */
#include <WebThingAdapter.h>

/* Scheduler */
#include <arduino-timer.h>

/* Compilation-time config */
#include <airly/Config.h>

/* Device */
#include <airly/Device.h>

// -------------------------------------------------------------------------- //
// Adapter, common properties
// -------------------------------------------------------------------------- //
/* Properties */
#include <airly/properties/Uptime.h>

#if !defined(SCHEDULER_INTERVAL_UPDATE_PROPERTIES)
#define SCHEDULER_INTERVAL_UPDATE_PROPERTIES 1000
#endif

static WebThingAdapter *adapter = nullptr;

static bool updateProperties(void *) {
  updateUptimeProperty();

  if (WiFi.status() == WL_CONNECTED) {
    adapter->update();
  }

  return true;
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Tasks scheduler
// -------------------------------------------------------------------------- //
#define SCHEDULER_TASKS 1

static Timer<SCHEDULER_TASKS> scheduler;

static void beginScheduler() {
  scheduler.every(SCHEDULER_INTERVAL_UPDATE_PROPERTIES, updateProperties);
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Thing
// -------------------------------------------------------------------------- //
static String getThingHostname() {
  auto macAddress = WiFi.macAddress();
  macAddress.replace(":", "");

  auto identity = String("airly-");
  identity += macAddress;
  identity.toLowerCase();
  return identity;
}

static String getThingIdentity() {
  auto macAddress = WiFi.macAddress();
  macAddress.replace(":", "");
  macAddress.toLowerCase();
  return macAddress;
}

static void beginWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.persistent(true);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void beginThing() {
  beginWiFi();

  auto thingHostname = getThingHostname();
  auto thingIdentity = getThingIdentity();

  WiFi.hostname(thingHostname);

  adapter = new WebThingAdapter(thingIdentity, WiFi.localIP());
  describeDevice(adapter);
  adapter->begin();

  beginScheduler();
}

void updateThing() { scheduler.tick(); }
// -------------------------------------------------------------------------- //
