#include "TimeUtils.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

std::string getTimeStampString()
{
	auto now = std::chrono::system_clock::now();
	time_t now_time = std::chrono::system_clock::to_time_t(now);

	std::tm localTime;

#ifdef _WIN32
	localtime_s(&localTime, &now_time);
#else
	localtime_r(&now_time, &localTime);
#endif

	std::ostringstream stream;

	stream << "Current time: "
		<< std::put_time(&localTime, "%Y-%m-%d %H:%M:%S")
		<< std::endl;

	return stream.str();
}

std::string getUptimeString()
{
	std::ifstream file("/proc/uptime");

	double uptimeSeconds;
	file >> uptimeSeconds;

	int days = static_cast<int>(uptimeSeconds) / 86400;
	int hours = static_cast<int>(uptimeSeconds) / 3600;
	int minutes = (static_cast<int>(uptimeSeconds) % 3600) / 60;
	int seconds = static_cast<int>(uptimeSeconds) % 60;

	std::ostringstream stream;
	stream << "Uptime: "
		<< days << "d "
		<< hours << "h "
		<< minutes << "m "
		<< seconds << "s"
		<< std::endl;

	return stream.str();
}