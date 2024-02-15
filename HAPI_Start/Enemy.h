#pragma once
#include "ComponentsMasterHeader.h"
#include "GameObject.h"


class Enemy : public Component
{
private:
	
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;

	std::vector<int> waypoints
	{
		/*x1,
		y1,
		x2,
		y2,
		x3,
		y3,
		x4,
		y4,*/
	};
	
	Collider2D* collider = new Collider2D;
	EnemyStateMachine* stateMachine = new EnemyStateMachine();
	const std::string name = "enemy";
	const std::string tag = "Enemy";
	//GameObject* bullet;
	const HAPI_TKeyboardData& keyData;
	std::string texture = "Data\\sampleSprite.png";
	
	


	std::vector<Component*> componentsToAdd = {
		stateMachine,
		collider,
		
	};
public:

	
	Enemy() : keyData(HAPI.GetKeyboardData()) { /*SetTexture("Data\\sampleSprite.png");*/ };

	void SetTexture(std::string newTexture) override
	{
		texture = newTexture;
	}
	const std::string GetName() override
	{
		return name;
	}
	std::string GetTexture() override
	{
		return "Data\\sampleSprite.png";
	}


	const std::string GetTag() override
	{
		return tag;
	}


	void PrintComponent() override
	{
		//std::cout << "Enemy" << std::endl;
	}

	int ReturnComponentAmount() override
	{
		return componentsToAdd.size();
	}

	Component* ReturnComponentVector(int componentIndex) override
	{
		return componentsToAdd[componentIndex];
	}

	void SetWaypoints(int newX1, int newY1, int newX2, int newY2, int newX3, int newY3, int newX4, int newY4);

	std::vector<int> GetWayPoints();



	~Enemy();


};

