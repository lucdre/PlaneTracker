#pragma once

#include <string>

struct SystemStats
{
    std::string timestamp;
    std::string uptime;

    double temperature;

    double memoryTotalMb;
    double memoryUsedMb;

    double cpuLoad;
};

SystemStats getSystemStats();

void printStats(const SystemStats& stats);