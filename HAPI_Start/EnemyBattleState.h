#pragma once
#include "EnemyBaseState.h"
#include "GameObject.h"
class EnemyBattleState : public EnemyBaseState
{
private:
	GameObject* gameObject = nullptr;

public:

	EnemyBattleState(EnemyStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;
};

