#include "TimeUtils.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

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

	stream << "Current time "
		<< std::put_time(&localTime, "%Y-%m-%d %H:%M:%S")
		<< std::endl;

	return stream.str();
}