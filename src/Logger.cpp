#include "Logger.h"
#include "TimeUtils.h"
#include "TemperatureReader.h"
#include "MemoryReader.h"
#include "CpuLoadReader.h"
#include "SystemStats.h"

#include <fstream>

void logSystemStats(const SystemStats& stats)
{
    std::ofstream file("monitor.csv", std::ios::app);

    file
        << stats.timestamp
        << ','
        << stats.temperature
        << ','
        << stats.memoryUsedMb
        << ','
        << stats.cpuLoad
        << std::endl;
}