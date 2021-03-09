#pragma once
#include <chrono>
class DurationTime
{
public:
	DurationTime() 
	{
	  start = std::chrono::high_resolution_clock::now();
	}

	~DurationTime()
	{
	  end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		cout << endl << "Duraton time: " << duration.count() << "s";
	}

private:
  std::chrono::time_point<std::chrono::steady_clock> start, end;
};

