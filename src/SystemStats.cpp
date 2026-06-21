#include "SystemStats.h"

#include "TimeUtils.h"
#include "TemperatureReader.h"
#include "MemoryReader.h"
#include "CpuLoadReader.h"

#include <iostream>

SystemStats getSystemStats()
{
    SystemStats stats;

    MemoryStats memory = getMemoryStats();

    stats.timestamp = getTimeStamp();
    stats.uptime = getUptime();
    stats.temperature = getTemperature();
    stats.memoryTotalMb = memory.totalMb;
    stats.memoryUsedMb = memory.usedMb;
    stats.cpuLoad = getCpuLoad();

    return stats;
}

void printStats(const SystemStats& stats)
{
    std::cout
        << "Current time: "
        << stats.timestamp
        << '\n';

    std::cout
        << "Uptime: "
        << stats.uptime
        << '\n';

    std::cout
        << "Temperature: "
        << stats.temperature
        << " C\n";

    std::cout
        << "Memory usage: "
        << stats.memoryUsedMb
        << " MB / "
        << stats.memoryTotalMb
        << " MB\n";

    std::cout
        << "CPU load: "
        << stats.cpuLoad
        << '\n';

    std::cout << '\n';
}