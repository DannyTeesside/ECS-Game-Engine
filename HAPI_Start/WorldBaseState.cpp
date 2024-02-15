#include "WorldBaseState.h"
#include "WorldStateMachine.h"

WorldBaseState::WorldBaseState(WorldStateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void WorldBaseState::Enter()
{
	std::cout << "World Base State Entered" << std::endl;
}

void WorldBaseState::Tick(float deltaTime)
{
	std::cout << "World Base State Working" << std::endl;
}

void WorldBaseState::Exit()
{
	std::cout << "World Base State Exit" << std::endl;
}
