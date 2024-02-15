#pragma once
#include "PlayerBaseState.h"
#include "GameObject.h"
class PlayerBattleState : public PlayerBaseState
{
private:
	const HAPISPACE::HAPI_TKeyboardData& keyData;
	GameObject* gameObject = nullptr;

public:

	PlayerBattleState(PlayerStateMachine* stateMachine);

	void Enter() override;

	void Tick(float deltaTime) override;

	void Exit() override;
};

