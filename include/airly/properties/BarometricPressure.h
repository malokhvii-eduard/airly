#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_BAROMETRIC_PRESSURE_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_BAROMETRIC_PRESSURE_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

void describeBarometricPressureProperty(ThingDevice* device);
void setBarometricPressureProperty(const float barometricPressure);

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_BAROMETRIC_PRESSURE_H_
