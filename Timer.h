#pragma once
#include <chrono>
class Timer
{
public:
	Timer();
	~Timer();

	void Start();
	void End();
	unsigned DurationInNanoSeconds();
	unsigned DurationInMicroSeconds();
	unsigned DurationInMilliSeconds();

private:
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;
};

