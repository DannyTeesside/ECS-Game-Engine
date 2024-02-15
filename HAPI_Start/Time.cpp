#include "Time.h"

void Time::SetStartTime()
{
	previousTime = clock();
}

void Time::SetCurrentTime()
{
	currentTime = clock();
}

void Time::UpdatePreviousTime()
{
	previousTime = currentTime;
}

float Time::GetDeltaTime()
{
	deltaTime = static_cast<float>(currentTime - previousTime) / CLOCKS_PER_SEC;
	return deltaTime;
}
