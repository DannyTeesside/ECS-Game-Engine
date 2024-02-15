#pragma once
#ifndef PLAYERBASESTATE_H
#define PLAYERBASESTATE_H

class PlayerStateMachine;

#include "State.h"


class PlayerBaseState : public State
{
protected:
	PlayerStateMachine* stateMachine = nullptr;

public:

	PlayerBaseState(PlayerStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;

};
#endif

