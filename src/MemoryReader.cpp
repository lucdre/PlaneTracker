#include "MemoryReader.h"

#include <fstream>
#include <sstream>
#include <string>

static double getMemoryTotalMb()
{
	std::ifstream file("/proc/meminfo");

	std::string label;
	double totalKb;

	file >> label >> totalKb;

	return totalKb / 1024.0;
}

double getMemoryUsedMb()
{
	std::ifstream file("/proc/meminfo");

	std::string label;
	double value;
	std::string unit;

	double totalKb = 0;
	double availableKb = 0;

	while (file >> label >> value >> unit)
	{
		if (label == "MemTotal:")
		{
			totalKb = value;
		}
		else if (label == "MemAvailable:")
		{
			availableKb = value;
		}

		if (totalKb > 0 && availableKb > 0)
		{
			break;
		}
	}

	return (totalKb - availableKb) / 1024.0;
}

std::string getMemoryString()
{
	std::ostringstream stream;

	stream << "Memory usage: "
		<< getMemoryUsedMb()
		<< " MB / "
		<< getMemoryTotalMb()
		<< " MB"
		<< '\n';

	return stream.str();
}