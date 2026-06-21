#include "CpuLoadReader.h"

#include <fstream>
#include <sstream>

double getCpuLoad()
{
    std::ifstream file("/proc/loadavg");

    double load;

    file >> load;

    return load;
}

std::string getCpuLoadString()
{
    std::ostringstream stream;

    stream << "CPU load: "
        << getCpuLoad()
        << '\n';

    return stream.str();
}