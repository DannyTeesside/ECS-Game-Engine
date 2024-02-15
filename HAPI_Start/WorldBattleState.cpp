#include "WorldBattleState.h"
#include "World.h"

WorldBattleState::WorldBattleState(WorldStateMachine* stateMachine) : WorldBaseState(stateMachine)
{
	this->stateMachine = stateMachine;
}

void WorldBattleState::Enter()
{
	stateMachine->worldInstance->SetBackground("BG2");
}

void WorldBattleState::Tick(float deltaTime)
{
}

void WorldBattleState::Exit()
{
}
