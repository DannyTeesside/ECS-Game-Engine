#pragma once
#include <iostream>
#include <ctime>
class Time
{
private:
	clock_t currentTime;
	clock_t previousTime;

	float deltaTime;

public:

	Time() {};

	void SetStartTime();

	void SetCurrentTime();

	void UpdatePreviousTime();

	float GetDeltaTime();

	~Time() {}

};

