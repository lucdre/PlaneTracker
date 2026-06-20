#include "TemperatureReader.h"

#include <fstream>
#include <sstream>

static double getTemperature()
{
	std::ifstream file("/sys/class/thermal/thermal_zone0/temp");

	int milliDegrees;
	file >> milliDegrees;

	return milliDegrees / 1000.0;
}

std::string getTemperatureString()
{
	double temperature = getTemperature();

	std::ostringstream stream;

	stream << "Temperature: "
		<< temperature
		<< " C"
		<< '\n';

	return stream.str();
}