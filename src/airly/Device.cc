#include <airly/Device.h>

/* Preprocessor-based localization */
#include <airly/I18n.h>

static const char* deviceCapabilities[] = {nullptr};
static ThingDevice device("0", i18n::DeviceTitle, deviceCapabilities);

void describeDevice(WebThingAdapter* adapter) { adapter->addDevice(&device); }
