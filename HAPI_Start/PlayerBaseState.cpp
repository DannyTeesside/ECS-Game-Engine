#include "PlayerBaseState.h"
#include "PlayerStateMachine.h"

PlayerBaseState::PlayerBaseState(PlayerStateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void PlayerBaseState::Enter()
{
	std::cout << "Player Base State Entered" << std::endl;
}

void PlayerBaseState::Tick(float deltaTime)
{
	std::cout << "Player Base State Working" << std::endl;
}

void PlayerBaseState::Exit()
{
	std::cout << "Player Base State Exit" << std::endl;
}
