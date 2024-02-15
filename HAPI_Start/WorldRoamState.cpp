#include "WorldRoamState.h"
#include "World.h"

WorldRoamState::WorldRoamState(WorldStateMachine* stateMachine) : WorldBaseState(stateMachine)
{
	this->stateMachine = stateMachine;
}

void WorldRoamState::Enter()
{
	/*if (stateMachine->worldInstance->GetBackgroundStatus())
	{
		stateMachine->worldInstance->SetBackground("BG2");
	}*/
	
	std::cout << "World Roam State Entered" << std::endl;
	
}

void WorldRoamState::Tick(float deltaTime)
{
	stateMachine->worldInstance->SetBackground("BG1");
}

void WorldRoamState::Exit()
{
	std::cout << "World Roam State Exit" << std::endl;
}
