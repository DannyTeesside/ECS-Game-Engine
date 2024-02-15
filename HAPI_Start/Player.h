#pragma once

#include "ComponentsMasterHeader.h"
#include <cmath>
class Player : public Component
{
private:
	std::string texture = "Data\\alphaThing.tga";
	Collider2D* collider = new Collider2D;
	PlayerStateMachine* stateMachine = new PlayerStateMachine;



	std::vector<Component*> componentsToAdd = {
		stateMachine,
		collider,

	};

	const std::string name = "Danny";
	const std::string tag = "Player";
	GameObject* bullet;
	//const HAPI_TKeyboardData& keyData;


	int xPos = 100;
	int yPos = 100;

	int speed = 5;
	

public:
	Player() {}
	//Player() : keyData(HAPI.GetKeyboardData())	{	}

	~Player()
	{
		
	}

	//void CreatePlayer(Graphics& graphics);

	//void DrawPlayer(Graphics& graphics);

	void Movement(const HAPI_TKeyboardData& keyData);
	void ControllerMovement(const HAPI_TControllerData& controllerData);
	void Update(const HAPI_TKeyboardData& keyData, const HAPI_TControllerData& controllerData);

	const std::string GetName() override
	{
		return name;
	}
	std::string GetTexture() override
	{
		return texture;
	}


	const std::string GetTag() override
	{
		return tag;
	}


	void Update() override
	{
		
		//Update(keyData, controllerData);
	}

	//void Update(const HAPI_TKeyboardData& keyData);

	int ReturnComponentAmount() override
	{
		return componentsToAdd.size();
	}

	Component* ReturnComponentVector(int componentIndex) override
	{
		return componentsToAdd[componentIndex];
	}


};

