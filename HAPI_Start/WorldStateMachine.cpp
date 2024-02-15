#include "WorldStateMachine.h"

void WorldStateMachine::EnterFreeRoamState()
{
	SwitchState(new WorldRoamState(this));
}

void WorldStateMachine::EnterBattleState()
{
	SwitchState(new WorldBattleState(this));
}
