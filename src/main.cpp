#include "TemperatureReader.h"
#include "TimeUtils.h"
#include "MemoryReader.h"
#include "CpuLoadReader.h"
#include "Logger.h"
#include "SystemStats.h"

#include <thread>
#include <iostream>
#include <chrono>

int main()
{
	while (true)
	{
		SystemStats stats = getSystemStats();

		printStats(stats);

		logSystemStats(stats);

		//Sleep
		std::this_thread::sleep_for(std::chrono::minutes(10));
	}

	return 0;
}