#include "TimeUtils.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

std::string getTimeStamp()
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

	stream << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

	return stream.str();
}

std::string getUptime()
{
	std::ifstream file("/proc/uptime");

	if (!file)
	{
		return "No uptime file found!";
	}

	double uptimeSeconds;
	file >> uptimeSeconds;

	int totalSeconds = static_cast<int>(uptimeSeconds);

	int days = totalSeconds / 86400;
	int hours = (totalSeconds % 86400) / 3600;
	int minutes = (totalSeconds % 3600) / 60;
	int seconds = totalSeconds % 60;

	std::ostringstream stream;
	stream
		<< days << "d "
		<< hours << "h "
		<< minutes << "m "
		<< seconds << "s";

	return stream.str();
}