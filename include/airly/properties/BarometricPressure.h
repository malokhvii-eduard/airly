#ifndef AIRLY_INCLUDE_AIRLY_PROPERTIES_BAROMETRIC_PRESSURE_H_
#define AIRLY_INCLUDE_AIRLY_PROPERTIES_BAROMETRIC_PRESSURE_H_

/* Config for WebThings framework */
#include <WebThingConfig.h>

/* WebThings framework */
#include <Thing.h>

#if defined(THING_HAS_BAROMETRIC_PRESSURE_PROPERTY)
void describeBarometricPressureProperty(ThingDevice* device);
void setBarometricPressureProperty(const float barometricPressure);
#endif

#endif  // AIRLY_INCLUDE_AIRLY_PROPERTIES_BAROMETRIC_PRESSURE_H_
