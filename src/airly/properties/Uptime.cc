#include <airly/Properties/Uptime.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Uptime */
#include <uptime.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

// -------------------------------------------------------------------------- //
// Property: Uptime (seconds, minutes, hours, days)
// -------------------------------------------------------------------------- //
enum UptimeUnit { Seconds, Minutes, Hours, Days };

static const char* propertyId PROGMEM = "uptime";
static String propertyValue = "";
static ThingProperty property(propertyId, i18n::UptimePropertyDescription,
                              STRING, nullptr);

static UptimeUnit currentUnit = UptimeUnit::Seconds;
static unsigned long lastDays = 0;
static unsigned long lastHours = 0;
static unsigned long lastMinutes = 0;
static unsigned long lastSeconds = 0;

static bool hasChanges(unsigned long current, long long last) {
  return current > 0 && current != last;
}

static void setUptimeProperty(const unsigned long uptime, const String unit) {
  propertyValue = String(uptime) + unit;
  property.setValue({.string = &propertyValue});
}

void describeUptimeProperty(ThingDevice* device) {
  property.title = i18n::UptimePropertyTitle;
  property.readOnly = true;

  device->addProperty(&property);
}

void updateUptimeProperty() {
  ::uptime::calculateUptime();

  auto days = ::uptime::getDays();
  auto hours = ::uptime::getHours();
  auto minutes = ::uptime::getMinutes();
  auto seconds = ::uptime::getSeconds();

  if (days == 1) currentUnit = Days;
  if (days == 0 && hours == 1) currentUnit = Hours;
  if (days == 0 && hours == 0 && minutes == 1) currentUnit = Minutes;

  if (currentUnit == Days && hasChanges(days, lastDays)) {
    lastDays = days;
    setUptimeProperty(days, "d");
  } else if (currentUnit == Hours && hasChanges(hours, lastHours)) {
    lastHours = hours;
    setUptimeProperty(hours, "h");
  } else if (currentUnit == Minutes && hasChanges(minutes, lastMinutes)) {
    lastMinutes = minutes;
    setUptimeProperty(minutes, "m");
  } else if (currentUnit == Seconds && hasChanges(seconds, lastSeconds)) {
    lastSeconds = seconds;
    setUptimeProperty(seconds, "s");
  }
}
// -------------------------------------------------------------------------- //
