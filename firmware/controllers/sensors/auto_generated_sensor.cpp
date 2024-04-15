#include "global.h"
#include "sensor_type.h"
// was generated automatically by rusEFI tool  from sensor_type.h // by enum_to_string.jar tool on Mon Apr 15 00:16:37 UTC 2024
// see also gen_config_and_enums.bat



const char *getSensorType(SensorType value){
switch(value) {
case SensorType::AcceleratorPedal:
  return "AcceleratorPedal";
case SensorType::AcceleratorPedalPrimary:
  return "AcceleratorPedalPrimary";
case SensorType::AcceleratorPedalSecondary:
  return "AcceleratorPedalSecondary";
case SensorType::AmbientTemperature:
  return "AmbientTemperature";
case SensorType::AuxAnalog1:
  return "AuxAnalog1";
case SensorType::AuxAnalog2:
  return "AuxAnalog2";
case SensorType::AuxAnalog3:
  return "AuxAnalog3";
case SensorType::AuxAnalog4:
  return "AuxAnalog4";
case SensorType::AuxAnalog5:
  return "AuxAnalog5";
case SensorType::AuxAnalog6:
  return "AuxAnalog6";
case SensorType::AuxAnalog7:
  return "AuxAnalog7";
case SensorType::AuxAnalog8:
  return "AuxAnalog8";
case SensorType::AuxLinear1:
  return "AuxLinear1";
case SensorType::AuxLinear2:
  return "AuxLinear2";
case SensorType::AuxSpeed1:
  return "AuxSpeed1";
case SensorType::AuxSpeed2:
  return "AuxSpeed2";
case SensorType::AuxTemp1:
  return "AuxTemp1";
case SensorType::AuxTemp2:
  return "AuxTemp2";
case SensorType::BarometricPressure:
  return "BarometricPressure";
case SensorType::BatteryVoltage:
  return "BatteryVoltage";
case SensorType::Clt:
  return "Clt";
case SensorType::CompressorDischargePressure:
  return "CompressorDischargePressure";
case SensorType::CompressorDischargeTemperature:
  return "CompressorDischargeTemperature";
case SensorType::DashOverrideBatteryVoltage:
  return "DashOverrideBatteryVoltage";
case SensorType::DashOverrideClt:
  return "DashOverrideClt";
case SensorType::DashOverrideRpm:
  return "DashOverrideRpm";
case SensorType::DashOverrideVehicleSpeed:
  return "DashOverrideVehicleSpeed";
case SensorType::DetectedGear:
  return "DetectedGear";
case SensorType::DriverThrottleIntent:
  return "DriverThrottleIntent";
case SensorType::EGT1:
  return "EGT1";
case SensorType::EGT2:
  return "EGT2";
case SensorType::EGT3:
  return "EGT3";
case SensorType::EGT4:
  return "EGT4";
case SensorType::EGT5:
  return "EGT5";
case SensorType::EGT6:
  return "EGT6";
case SensorType::EGT7:
  return "EGT7";
case SensorType::EGT8:
  return "EGT8";
case SensorType::FuelEthanolPercent:
  return "FuelEthanolPercent";
case SensorType::FuelLevel:
  return "FuelLevel";
case SensorType::FuelPressureHigh:
  return "FuelPressureHigh";
case SensorType::FuelPressureInjector:
  return "FuelPressureInjector";
case SensorType::FuelPressureLow:
  return "FuelPressureLow";
case SensorType::FuelTemperature:
  return "FuelTemperature";
case SensorType::Iat:
  return "Iat";
case SensorType::IdlePosition:
  return "IdlePosition";
case SensorType::IgnKeyVoltage:
  return "IgnKeyVoltage";
case SensorType::InputShaftSpeed:
  return "InputShaftSpeed";
case SensorType::Invalid:
  return "Invalid";
case SensorType::Lambda1:
  return "Lambda1";
case SensorType::Lambda2:
  return "Lambda2";
case SensorType::LuaGauge1:
  return "LuaGauge1";
case SensorType::LuaGauge2:
  return "LuaGauge2";
case SensorType::LuaGauge3:
  return "LuaGauge3";
case SensorType::LuaGauge4:
  return "LuaGauge4";
case SensorType::LuaGauge5:
  return "LuaGauge5";
case SensorType::LuaGauge6:
  return "LuaGauge6";
case SensorType::LuaGauge7:
  return "LuaGauge7";
case SensorType::LuaGauge8:
  return "LuaGauge8";
case SensorType::Maf:
  return "Maf";
case SensorType::Maf2:
  return "Maf2";
case SensorType::Map:
  return "Map";
case SensorType::Map2:
  return "Map2";
case SensorType::MapFast:
  return "MapFast";
case SensorType::MapFast2:
  return "MapFast2";
case SensorType::MapSlow:
  return "MapSlow";
case SensorType::MapSlow2:
  return "MapSlow2";
case SensorType::OilPressure:
  return "OilPressure";
case SensorType::OilTemperature:
  return "OilTemperature";
case SensorType::PlaceholderLast:
  return "PlaceholderLast";
case SensorType::RangeInput1:
  return "RangeInput1";
case SensorType::RangeInput2:
  return "RangeInput2";
case SensorType::RangeInput3:
  return "RangeInput3";
case SensorType::RangeInput4:
  return "RangeInput4";
case SensorType::RangeInput5:
  return "RangeInput5";
case SensorType::RangeInput6:
  return "RangeInput6";
case SensorType::Rpm:
  return "Rpm";
case SensorType::ThrottleInletPressure:
  return "ThrottleInletPressure";
case SensorType::Tps1:
  return "Tps1";
case SensorType::Tps1Primary:
  return "Tps1Primary";
case SensorType::Tps1Secondary:
  return "Tps1Secondary";
case SensorType::Tps2:
  return "Tps2";
case SensorType::Tps2Primary:
  return "Tps2Primary";
case SensorType::Tps2Secondary:
  return "Tps2Secondary";
case SensorType::TurbochargerSpeed:
  return "TurbochargerSpeed";
case SensorType::VehicleSpeed:
  return "VehicleSpeed";
case SensorType::WastegatePosition:
  return "WastegatePosition";
case SensorType::WheelSlipRatio:
  return "WheelSlipRatio";
  }
 return NULL;
}
