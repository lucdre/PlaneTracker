#include "TemperatureReader.h"
#include "TimeUtils.h"

#include <thread>
#include <iostream>
#include <chrono>

int main()
{
	while (true)
	{
		//Get the current date
		std::cout << getTimeStamp();

		//Get the temperature
		std::cout << getTemperatureString();

		//Sleep for 1 minute
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}

	return 0;
}