#include <airly/OtaUpdate.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* OTA updates server */
#include <AsyncElegantOTA.h>

/* Compilation-time config */
#include <airly/Config.h>

/* Utilities */
#include <airly/Util.h>

static const char* username = "root";
static AsyncWebServer server(OTA_UPDATES_PORT);

static String getPassword() {
  auto password = getMacAddressWithoutColon();
  password.toLowerCase();
  return password;
}

void beginOtaUpdates() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->redirect("/update");
  });

  AsyncElegantOTA.begin(&server, username, getPassword().c_str());
  server.begin();
}
