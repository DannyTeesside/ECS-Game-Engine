#include "StateMachine.h"

void StateMachine::Update()
{
	time.SetCurrentTime();
	currentState ? currentState->Tick(time.GetDeltaTime()) : static_cast<void>(0);
	time.UpdatePreviousTime();
}

void StateMachine::SwitchState(State* newState)
{
	currentState ? currentState->Exit() : static_cast<void>(0);
	if(currentState)delete currentState;
	currentState = newState;
	currentState ? currentState->Enter() : static_cast<void>(0);
}
