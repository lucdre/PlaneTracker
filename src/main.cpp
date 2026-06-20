#include "TemperatureReader.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>

int main()
{
	while (true)
	{
		//Get the current date
		
		auto now = std::chrono::system_clock::now();
		time_t now_time = std::chrono::system_clock::to_time_t(now);

		std::tm localTime;
#ifdef _WIN32
        localtime_s(&localTime, &now_time);
#else
        localtime_r(&now_time, &localTime);
#endif

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