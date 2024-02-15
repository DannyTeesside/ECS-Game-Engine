#pragma once
#include "PlayerBaseState.h"
#include "GameObject.h"
class PlayerRoamState : public PlayerBaseState
{

private:
	const HAPISPACE::HAPI_TKeyboardData& keyData;

	GameObject* gameObject = nullptr;

	int speed = 200;

public:
	PlayerRoamState(PlayerStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Tick(float deltaTime, const HAPISPACE::HAPI_TKeyboardData& keyData);

	void Exit() override;
};

