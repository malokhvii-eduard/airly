#include <airly/properties/CarbonDioxide.h>

/* AVR low-level */
#include <avr/pgmspace.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

// -------------------------------------------------------------------------- //
// Property: Carbon dioxide (ppm)
// -------------------------------------------------------------------------- //
#if defined(THING_HAS_CARBON_DIOXIDE_PROPERTY)

static const char* propertyId PROGMEM = "carbonDioxide";
static ThingProperty property(propertyId,
                              i18n::CarbonDioxidePropertyDescription, INTEGER,
                              "ConcentrationProperty");

void describeCarbonDioxideProperty(ThingDevice* device) {
  property.title = i18n::CarbonDioxidePropertyTitle;
  property.unit = "ppm";
  property.minimum = 0;
  property.maximum = 5000;
  property.readOnly = true;
  property.setValue({.integer = 0});

  device->addProperty(&property);
}

void setCarbonDioxideProperty(const unsigned short carbonDioxide) {
  property.setValue({.integer = carbonDioxide});
}

#endif
// -------------------------------------------------------------------------- //
