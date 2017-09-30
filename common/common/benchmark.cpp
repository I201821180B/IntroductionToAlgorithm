#include "benchmark.h"

void CPUTimer::Start()
{
	start = std::chrono::time_point_cast<microsecond_type>(std::chrono::system_clock::now());
	running = true;
}

void CPUTimer::Stop()
{
	if (running)
	{
		stop = std::chrono::time_point_cast<microsecond_type>(std::chrono::system_clock::now());
		running = false;
	}
}

long long CPUTimer::microsecond()
{
	if (running)
	{
		Stop();
	}
	elapseTime = stop - start;
	return elapseTime.count();
}
