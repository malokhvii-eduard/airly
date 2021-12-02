#include <airly/properties/Temperature.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

// -------------------------------------------------------------------------- //
// Property: Temperature (°C)
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_BME280)

static const char* propertyId PROGMEM = "temeperature";
static ThingProperty property(propertyId, i18n::TemperaturePropertyDescription,
                              NUMBER, "TemperatureProperty");

void describeTemperatureProperty(ThingDevice* device) {
  property.title = i18n::TemperaturePropertyTitle;
  property.unit = "degree celsius";
  property.minimum = -45;
  property.maximum = 85;
  property.readOnly = true;

  device->addProperty(&property);
}

void setTemperatureProperty(const float temperature) {
  property.setValue({.number = temperature});
}

#endif
// -------------------------------------------------------------------------- //
