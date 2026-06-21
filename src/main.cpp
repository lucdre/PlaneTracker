#include "TemperatureReader.h"
#include "TimeUtils.h"
#include "MemoryReader.h"
#include "CpuLoadReader.h"

#include <thread>
#include <iostream>
#include <chrono>

int main()
{
	while (true)
	{
		//Get the current date and uptime
		std::cout << getTimeStampString();
		std::cout << getUptimeString();

		//Get the temperature
		std::cout << getTemperatureString();

		//Get the memory usage
		std::cout << getMemoryString();

		//Get the CPU load
		std::cout << getCpuLoadString();

		std::cout << '\n';

		//Sleep for 1 minute
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}

	return 0;
}