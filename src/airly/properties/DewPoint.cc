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

float calculateDewPoint(const float temperature, const float humidity) {
  auto t = round(temperature);
  auto h = round(humidity);
  if (t < -45 || t > 65 || h == 0) {
    return NAN;
  }

  float a = 17.62;
  float b = 243.12;

  /**
   * Magnus-Tetens formula (Sonntag90):
   *
   * Ts = (bα(T,RH)) / (a - α(T,RH))
   *
   * Ts is the dew point;
   * T is the temperature;
   * RH is the relative humidity of the air;
   * a and b are coefficients. For Sonntag90 constant set, a = 17.62
   * and b = 243.12°C;
   * α(T,RH) = ln(RH/100) + aT/(b+T)
   */
  float alpha = log(humidity / 100) + a * temperature / (b + temperature);
  float dewPoint = (b * alpha) / (a - alpha);

  return dewPoint;
}

#endif
// -------------------------------------------------------------------------- //
