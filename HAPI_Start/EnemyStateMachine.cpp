#include "EnemyStateMachine.h"
#include "EntityMasterHeader.h"

EnemyStateMachine::EnemyStateMachine()
{

	//SetWaypoints(x1, y1, x2, y2, x3, y3, x4, y4);
	EnterFreeRoamState();
}

void EnemyStateMachine::EnterFreeRoamState()
{
	SwitchState(new EnemyRoamState(this));
}

void EnemyStateMachine::EnterBattleState()
{
	SwitchState(new EnemyBattleState(this));
}

void EnemyStateMachine::SetWaypoints()
{
	waypoints.push_back(waypoint1);
	waypoints.push_back(waypoint2);
	waypoints.push_back(waypoint3);
	waypoints.push_back(waypoint4);
	std::vector<int> enemyWaypoints = gameObject->GetComponent<Enemy>()->GetWayPoints();
	//std::cout << enemyWaypoints[1];

	//waypoints[0].x = enemyWaypoints[0];
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		for (size_t j = 0; j < enemyWaypoints.size(); j+=2)
		{
			waypoints[i].x = enemyWaypoints[j];
			waypoints[i].y = enemyWaypoints[j+1];
			//std::cout << waypoints[i].x << "," << waypoints[i].y << std::endl;
			i++;
		}
	}
}

bool EnemyStateMachine::AtWaypoint()
{
	if (gameObject->transform->position.x >= GetCurrentWaypoint().x - 5 && gameObject->transform->position.y >= GetCurrentWaypoint().y - 5
		&& gameObject->transform->position.x <= GetCurrentWaypoint().x + 5 && gameObject->transform->position.y <= GetCurrentWaypoint().y + 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}
