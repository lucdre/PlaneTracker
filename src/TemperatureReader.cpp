#include "TemperatureReader.h"

#include <fstream>

double getTemperature()
{
	std::ifstream file("/sys/class/thermal/thermal_zone0/temp");

	int milliDegrees;
	file >> milliDegrees;

	return milliDegrees / 1000.0;
}