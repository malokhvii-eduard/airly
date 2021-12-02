#include <airly/properties/Humidity.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

// -------------------------------------------------------------------------- //
// Property: Humidity, %
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_BME280)

static const char* propertyId PROGMEM = "humidity";
static ThingProperty property(propertyId, i18n::HumidityPropertyDescription,
                              NUMBER, "HumidityProperty");

void describeHumidityProperty(ThingDevice* device) {
  property.title = i18n::HumidityPropertyTitle;
  property.unit = "%";
  property.minimum = 0;
  property.maximum = 100;
  property.readOnly = true;

  device->addProperty(&property);
}

void setHumidityProperty(const float humidity) {
  property.setValue({.number = humidity});
}

#endif
// -------------------------------------------------------------------------- //
