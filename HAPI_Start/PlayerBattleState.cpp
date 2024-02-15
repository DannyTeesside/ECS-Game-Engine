#include "PlayerBattleState.h"

PlayerBattleState::PlayerBattleState(PlayerStateMachine* stateMachine) : PlayerBaseState(stateMachine), keyData(HAPI.GetKeyboardData())
{
	
}

void PlayerBattleState::Enter()
{
	if (!gameObject)gameObject = stateMachine->GetGameObject();
	gameObject->transform->position.x = 150;
	gameObject->transform->position.y = 400;
}

void PlayerBattleState::Tick(float deltaTime)
{
}

void PlayerBattleState::Exit()
{
}
