#include "EnemyBaseState.h"

EnemyBaseState::EnemyBaseState(EnemyStateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void EnemyBaseState::Enter()
{
	std::cout << "Enemy Base State Entered" << std::endl;
}

void EnemyBaseState::Tick(float deltaTime)
{
	std::cout << "Enemy Base State Working" << std::endl;
}

void EnemyBaseState::Exit()
{
	std::cout << "Enemy Base State Exit" << std::endl;
}
