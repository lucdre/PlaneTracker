#include "MemoryReader.h"

#include <fstream>
#include <sstream>
#include <string>

MemoryStats getMemoryStats()
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

	MemoryStats memory{};

	memory.totalMb = totalKb / 1024.0;
	memory.usedMb = (totalKb - availableKb) / 1024.0;

	return memory;
}