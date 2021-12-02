#include <airly/Properties/DewPoint.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

// -------------------------------------------------------------------------- //
// Property: Dew point (°C)
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_BME280)

static const char* propertyId PROGMEM = "dewPoint";
static ThingProperty property(propertyId, i18n::DewPointPropertyDescription,
                              NUMBER, nullptr);

void describeDewPointProperty(ThingDevice* device) {
  property.title = i18n::DewPointPropertyTitle;
  property.unit = "degree celsius";
  property.readOnly = true;

  device->addProperty(&property);
}

void setDewPointProperty(const float dewPoint) {
  property.setValue({.number = dewPoint});
}

#endif
// -------------------------------------------------------------------------- //
