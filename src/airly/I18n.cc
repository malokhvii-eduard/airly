#include <airly/i18n.h>

// -------------------------------------------------------------------------- //
// Translations: stub
// -------------------------------------------------------------------------- //
#if defined(LANG_UNDEFINED)

namespace i18n {

const char* DeviceTitle = "";
const char* UptimePropertyDescription = "";
const char* UptimePropertyTitle = "";

#if defined(THING_HAS_BME280)
const char* BarometricPressurePropertyDescription = "";
const char* BarometricPressurePropertyTitle = "";
const char* DewPointPropertyDescription = "";
const char* DewPointPropertyTitle = "";
const char* HumidityPropertyDescription = "";
const char* HumidityPropertyTitle = "";
const char* TemperaturePropertyDescription = "";
const char* TemperaturePropertyTitle = "";
#endif

#if defined(THING_HAS_MHZ19)
const char* CarbonDioxidePropertyDescription = "";
const char* CarbonDioxidePropertyTitle = "";
#endif

}  // namespace i18n

#endif
// -------------------------------------------------------------------------- //
