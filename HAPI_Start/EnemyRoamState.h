#pragma once
#include "EnemyBaseState.h"
#include "GameObject.h"
class EnemyRoamState : public EnemyBaseState
{
private:

	GameObject* gameObject = nullptr;

	int speed = 1;

public:
	EnemyRoamState(EnemyStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;
};

