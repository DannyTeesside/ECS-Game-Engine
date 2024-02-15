#include "EnemyBattleState.h"

EnemyBattleState::EnemyBattleState(EnemyStateMachine* stateMachine) : EnemyBaseState(stateMachine)
{
}

void EnemyBattleState::Enter()
{
	if (!gameObject)gameObject = stateMachine->GetGameObject();
	gameObject->transform->position.x = 650;
	gameObject->transform->position.y = 350;
}

void EnemyBattleState::Tick(float deltaTime)
{
}

void EnemyBattleState::Exit()
{
}
