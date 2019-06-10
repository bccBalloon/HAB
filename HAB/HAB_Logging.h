#ifndef HAB_LOGGING_H
#define HAB_LOGGING_H
#include "HAB_GPS.h"
#include "HAB_Sensors.h"
#include "HAB_Thermistor.h"
#include "HAB_Door.h"

namespace HAB {
namespace Logging {

class MissionData {
public:
  MissionData(const char* rawGpsData, 
              long gpsAltitude, 
              Sensors::TemperatureData onboardTemperature,
              Sensors::TemperatureData outdoorTopTemperature,
              Sensors::TemperatureData outdoorBottomTemperature,
              Sensors::PressureData pressure,
              Door::DoorStatus door1Status, 
              Door::DoorStatus door2Status);
  static String getTitles();
  String toString();
  // missionData
  typedef struct {
    const char* rawGpsData;
    long gpsAltitude;
    Sensors::TemperatureData onboardTemperature;
    Sensors::TemperatureData outdoorTopTemperature;
    Sensors::TemperatureData outdoorBottomTemperature;
    Sensors::PressureData pressure;
    Door::DoorStatus door1Status;
    Door::DoorStatus door2Status;
  } Data;
 private:
  Data data;
};

bool init();
void logMissionData(String data);
void logSystemData(String data);

} // namespace Logging
} // namespace HAB

#endif // HAB_LOGGING_H