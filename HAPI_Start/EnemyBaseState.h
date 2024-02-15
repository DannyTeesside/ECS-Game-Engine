#pragma once
#ifndef ENEMYBASESTATE_H
#define ENEMYBASESTATE_H

class EnemyStateMachine;

#include "State.h"

class EnemyBaseState : public State
{
protected:
	EnemyStateMachine* stateMachine = nullptr;

public:

	EnemyBaseState(EnemyStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;
};

#endif

