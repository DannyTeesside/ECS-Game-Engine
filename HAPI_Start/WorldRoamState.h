#pragma once
#include "WorldBaseState.h"
#include "GameObject.h"
class WorldRoamState : public WorldBaseState
{
private:
	//GameObject* gameObject = nullptr;

public:

	WorldRoamState(WorldStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;

};