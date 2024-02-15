#pragma once
#ifndef WORLDBASESTATE_H
#define WORLDBASESTATE_H

class WorldStateMachine;

#include "State.h"


class WorldBaseState : public State
{
protected:
	WorldStateMachine* stateMachine = nullptr;

public:

	WorldBaseState(WorldStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;

};
#endif
