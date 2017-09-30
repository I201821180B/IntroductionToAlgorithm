#ifndef _BENCHMARK_H_
#define _BENCHMARK_H_

#include <chrono>
#include <ratio>

class CPUTimer
{
	
public:
	typedef std::chrono::duration<long long, std::micro> microsecond_type;
	typedef std::chrono::time_point<std::chrono::system_clock, microsecond_type> ptime;
	CPUTimer() : running(false) {}
	void Start();
	void Stop();
	long long microsecond();
private:
	ptime start;
	ptime stop; 
	std::chrono::microseconds elapseTime;
	bool running;
};

#endif