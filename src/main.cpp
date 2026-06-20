#include "TemperatureReader.h"
#include "TimeUtils.h"
#include "MemoryReader.h"

#include <thread>
#include <iostream>
#include <chrono>

int main()
{
	while (true)
	{
		//Get the current date
		std::cout << getTimeStampString();

		//Get the temperature
		std::cout << getTemperatureString();

		//Get the memory usage
		std::cout << getMemoryString();

		std::cout << '\n';

		//Sleep for 1 minute
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}

	return 0;
}