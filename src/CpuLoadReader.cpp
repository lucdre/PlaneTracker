#include "CpuLoadReader.h"

#include <fstream>
#include <sstream>

double getCpuLoad()
{
    std::ifstream file("/proc/loadavg");

    if (!file)
    {
        return 0;
    }

    double load;

    file >> load;

    return load;
}