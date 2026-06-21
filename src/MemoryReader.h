#pragma once

struct MemoryStats
{
	double totalMb;
	double usedMb;
};

MemoryStats getMemoryStats();