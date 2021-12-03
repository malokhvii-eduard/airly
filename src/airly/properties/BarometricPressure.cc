#include <airly/properties/BarometricPressure.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

// -------------------------------------------------------------------------- //
// Property: Barometric pressure (hPa)
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)

static const char* propertyId PROGMEM = "barometricPressure";
static ThingProperty property(propertyId,
                              i18n::BarometricPressurePropertyDescription,
                              NUMBER, "BarometricPressureProperty");

void describeBarometricPressureProperty(ThingDevice* device) {
  property.title = i18n::BarometricPressurePropertyTitle;
  property.unit = "hectopascal";
  property.minimum = 300;
  property.maximum = 1100;
  property.readOnly = true;

  device->addProperty(&property);
}

void setBarometricPressureProperty(const float barometricPressure) {
  auto hectopascals = barometricPressure / 100;
  property.setValue({.number = hectopascals});
}

#endif
// -------------------------------------------------------------------------- //
