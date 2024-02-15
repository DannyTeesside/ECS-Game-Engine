#include "PlayerRoamState.h"
#include "World.h"
//#include "PlayerBaseState.h"

PlayerRoamState::PlayerRoamState(PlayerStateMachine* stateMachine) : PlayerBaseState(stateMachine), keyData(HAPI.GetKeyboardData())
{
}

void PlayerRoamState::Enter()
{
	
	std::cout << "Player Roam State Entered" << std::endl;
}

void PlayerRoamState::Tick(float deltaTime)
{
	if(!gameObject)gameObject = stateMachine->GetGameObject();
	const HAPISPACE::HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);
	/*if (controllerData.isAttached)
	{
		std::cout << "controller connected" << std::endl;
	}
	else
	{
		std::cout << "controller not connected" << std::endl;
	}*/
	Tick(deltaTime, keyData);
}

void PlayerRoamState::Tick(float deltaTime, const HAPISPACE::HAPI_TKeyboardData& keyData)
{
	if (keyData.scanCode['W'] || keyData.scanCode[HK_UP])
	{
		gameObject->transform->position.y -= (speed * deltaTime);
	}
	if (keyData.scanCode['S'] || keyData.scanCode[HK_DOWN])
	{
		gameObject->transform->position.y += (speed * deltaTime);  // Fix: Multiply by deltaTime
	}
	if (keyData.scanCode['A'] || keyData.scanCode[HK_LEFT])
	{
		gameObject->transform->position.x -= (speed * deltaTime);
	}
	if (keyData.scanCode['D'] || keyData.scanCode[HK_RIGHT])
	{
		gameObject->transform->position.x += (speed * deltaTime);
	}

	if (gameObject->DetectCollisions("Enemy"))
	{
		GameObject* collidingObject = gameObject->GetCollidingObject();
		gameObject->worldInstance->StartBattle(collidingObject);
		stateMachine->EnterBattleState();
		/*std::cout << gameObject->GetCollidingObject()->GetName();
		std::cout << "Collision";*/
	}

	/*if (keyData.scanCode[HK_SPACE])
	{
		stateMachine->EnterBattleState();

	}*/
}

void PlayerRoamState::Exit()
{
	std::cout << "Player Roam State Exit" << std::endl;
}
