#include "Enemy.h"
#include "EntityMasterHeader.h"
#include "World.h"



//void Enemy::Update(const HAPI_TKeyboardData& keyData) 
//{
//	gameObject->transform->position.x++;
//
//	
//	if (keyData.scanCode[HK_SPACE])
//	{
//		std::cout << GetName() << worldInstance;
//		if (worldInstance != nullptr)
//		{
//			//world1->Instantiate(world1->enemy, gameObject->transform->position.x - 50, gameObject->transform->position.y);
//		}
//		std::cout << GetName() << worldInstance;
//		//newBullet->GetComponent<Enemy>()->SetWorld(world1);
//		//entities.push_back(henry);
//
//	}
//}

void Enemy::SetWaypoints(int newX1, int newY1, int newX2, int newY2, int newX3, int newY3, int newX4, int newY4)
{
	x1 = newX1;
	y1 = newY1;
	x2 = newX2;
	y2 = newY2;
	x3 = newX3;
	y3 = newY3;
	x4 = newX4;
	y4 = newY4;
	waypoints.push_back(x1);
	waypoints.push_back(y1);
	waypoints.push_back(x2);
	waypoints.push_back(y2);
	waypoints.push_back(x3);
	waypoints.push_back(y3);
	waypoints.push_back(x4);
	waypoints.push_back(y4);
}

std::vector<int> Enemy::GetWayPoints()
{
	return waypoints;
}

Enemy::~Enemy()
{
	//commented out as this caused read violation in GameObject destructor loop

	/*for each (Component * component in componentsToAdd)
	{
		delete component;
	}*/
}
