#include "PlayerStateMachine.h"

void PlayerStateMachine::EnterFreeRoamState()
{
	SwitchState(new PlayerRoamState(this));
}

void PlayerStateMachine::EnterBattleState()
{
	SwitchState(new PlayerBattleState(this));
}
