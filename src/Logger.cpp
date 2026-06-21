#include "Logger.h"
#include "TimeUtils.h"
#include "TemperatureReader.h"
#include "MemoryReader.h"
#include "CpuLoadReader.h"

#include <fstream>

void logSample()
{
    std::ofstream file("monitor.csv", std::ios::app);

    file
        << getTimeStamp()
        << ','
        << getTemperature()
        << ','
        << getMemoryUsedMb()
        << ','
        << getCpuLoad()
        << std::endl;
}