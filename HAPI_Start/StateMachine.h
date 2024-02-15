#pragma once

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include "Component.h"
#include "Time.h"
class StateMachine : public Component
{
private:
	Time time;
public:

	StateMachine() { }

	State* currentState = nullptr;

	void Update();
	void SwitchState(State* newState);

	~StateMachine()
	{
		if (currentState)delete currentState;
	}
};

#endif

