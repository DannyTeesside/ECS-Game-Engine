#pragma once

#ifndef WORLDSTATEMACHINE_H
#define WORLDSTATEMACHINE_H

#include "WorldRoamState.h"
#include "WorldBattleState.h"
#include "StateMachine.h"
class WorldStateMachine : public StateMachine
{
private:


public:
	//const HAPISPACE::HAPI_TKeyboardData& keyData;
	WorldStateMachine() { EnterFreeRoamState(); }


	void EnterFreeRoamState();
	void EnterBattleState();

	void PrintComponent() override
	{
		std::cout << "World State Machine" << std::endl;
	}

	GameObject* GetGameObject()
	{
		return gameObject;
	}
};


#endif
