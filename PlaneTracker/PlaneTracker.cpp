// PlaneTracker.cpp : Defines the entry point for the application.
//

#include "PlaneTracker.h"
#include <chrono>
#include <thread>
#include <fstream>

double getTemperature()
{
	std::ifstream file("/sys/class/thermal/thermal_zone0/temp");

	int milliDegrees;
	file >> milliDegrees;

	return milliDegrees / 1000.0;
}

int main()
{
	while (true)
	{
		//Get the current date
		auto now = std::chrono::system_clock::now();
		time_t now_time = std::chrono::system_clock::to_time_t(now);

		std::tm localTime;
		localtime_s(&localTime, &now_time);

		std::cout << "Current time "
			<< std::put_time(&localTime, "%Y-%m-%d %H:%M:%S")
			<< std::endl;

		//Get the temperature
		double temperature = getTemperature();
		std::cout << "Temperature: "
			<< temperature
			<< " C"
			<< std::endl;

		//Sleep for 1 minute
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}

	return 0;	
}
