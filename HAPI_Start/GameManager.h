#pragma once
#include "ComponentsMasterHeader.h"
#include "World.h"
#include "Enemy.h"

class GameManager : public Component
{
private:
	std::string texture = "Data\\emptyObject.png";
	std::string background;
	WorldStateMachine* stateMachine = new WorldStateMachine;

	std::vector<std::string> gameBackgrounds = {
		"Data\\BG.png",
		"Data\\background.tga"

	};

	std::vector<Component*> componentsToAdd = {
		stateMachine,

	};

	const std::string name = "Game Manager";
	const std::string tag = "None";


public:


	const std::string GetName() override
	{
		return name;
	}
	std::string GetTexture() override
	{
		return texture;
	}

	std::vector<std::string> GetBackgrounds()
	{
		return gameBackgrounds;
	}


	const std::string GetTag() override
	{
		return tag;
	}


	void Update() override
	{
		
		
	}


	int ReturnComponentAmount() override
	{
		return componentsToAdd.size();
	}

	Component* ReturnComponentVector(int componentIndex) override
	{
		return componentsToAdd[componentIndex];
	}

	void SpawnEnemy()
	{
		worldInstance->Instantiate<Enemy>(200, 200);
	}

};

