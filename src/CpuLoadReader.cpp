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

std::string getCpuLoadString()
{
    std::ostringstream stream;

    double load = getCpuLoad();

    stream << "CPU load: "
        << load
        << '\n';

    return stream.str();
}