#include "EnemyRoamState.h"

EnemyRoamState::EnemyRoamState(EnemyStateMachine* stateMachine) : EnemyBaseState(stateMachine)
{
}

void EnemyRoamState::Enter()
{
	
}

void EnemyRoamState::Tick(float deltaTime)
{
	if (!gameObject)gameObject = stateMachine->GetGameObject();
	if (stateMachine->GetWaypoints().empty())
	{
		//std::cout << "empty";
		stateMachine->SetWaypoints();
	}

	if (stateMachine->GetCurrentWaypoint().x != 0 && stateMachine->GetCurrentWaypoint().y != 0)
	{
		if (stateMachine->AtWaypoint())
		{
			stateMachine->CycleWayPoint();
		}
		gameObject->transform->MoveTowards( stateMachine->GetCurrentWaypoint(), speed);
		//gameObject->transform->position.x--;

	}
		//std::cout << stateMachine->GetCurrentWaypoint().x <<","<< stateMachine->GetCurrentWaypoint().y << std::endl;


	//for (Vector2 waypoint : stateMachine->GetWaypoints())
	//{
	//	if (waypoint.x != 0 && waypoint.y != 0)
	//	{
	//		//while (gameObject->transform->position.x != waypoint.x && gameObject->transform->position.y != waypoint.y)
	//		//{
	//			gameObject->transform->position.x--;
	//			std::cout << "waypoint not reached" << std::endl;
	//		//}
	//	}
	//}
}

void EnemyRoamState::Exit()
{
}
