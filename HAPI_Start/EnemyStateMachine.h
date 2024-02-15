#pragma once

#ifndef ENEMYSTATEMACHINE_H
#define ENEMYSTATEMACHINE_H

class EnemyBaseState;

#include "EnemyRoamState.h"
#include "EnemyBattleState.h"
#include "StateMachine.h"
class EnemyStateMachine : public StateMachine
{
private:


	Vector2 waypoint1;
	Vector2 waypoint2;
	Vector2 waypoint3;
	Vector2 waypoint4;

	std::vector<Vector2> waypoints
	{

	};

	int currentwayPointIndex = 0;

	
public:

	EnemyStateMachine();

	void EnterFreeRoamState();
	void EnterBattleState();

	void PrintComponent() override
	{
		std::cout << "Enemy State Machine" << std::endl;
	}

	GameObject* GetGameObject()
	{
		return gameObject;
	}

	void SetWaypoints();

	std::vector<Vector2> GetWaypoints()
	{
		return waypoints;
	}
	Vector2 GetFirstWaypoint()
	{
		return waypoints[0];
	}
	int GetNextWaypoint(int i)
	{
		if (i >= GetWaypoints().size() - 1)
		{
			return 0;
		}
		else
		{
			return i + 1;
		}
	}
	void CycleWayPoint()
	{
		currentwayPointIndex = GetNextWaypoint(currentwayPointIndex);
	}

	Vector2 GetCurrentWaypoint()
	{
		//std::cout << waypoints[currentwayPointIndex].x;
		return waypoints[currentwayPointIndex];
	}

	bool AtWaypoint();
};

#endif

