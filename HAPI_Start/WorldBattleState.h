#pragma once
#include "WorldBaseState.h"
#include "GameObject.h"
class WorldBattleState : public WorldBaseState
{
private:
	//GameObject* gameObject = nullptr;
	GameObject* player = nullptr;
	GameObject* enemy = nullptr;

public:

	WorldBattleState(WorldStateMachine* stateMachine);

	void Enter() override;

	void Enter(GameObject* enemy);

	void Tick(float deltaTime) override;

	void Exit() override;

};

