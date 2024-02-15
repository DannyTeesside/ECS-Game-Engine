#pragma once

#ifndef PLAYERSTATEMACHINE_H
#define PLAYERSTATEMACHINE_H

class PlayerBaseState;
//class PlayerRoamState;

#include "PlayerRoamState.h"
#include "PlayerBattleState.h"
#include "StateMachine.h"
#include <HAPI_lib.h>
#include <iostream>

class PlayerStateMachine : public StateMachine
{
private:


public:
	//const HAPISPACE::HAPI_TKeyboardData& keyData;
	PlayerStateMachine() { EnterFreeRoamState(); }
	

	void EnterFreeRoamState();
	void EnterBattleState();

	void PrintComponent() override
	{
		std::cout << "Player State Machine" << std::endl;
	}

	GameObject* GetGameObject()
	{
		return gameObject;
	}

};

#endif

