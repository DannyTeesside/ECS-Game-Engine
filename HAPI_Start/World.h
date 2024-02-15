#pragma once
#include "Graphics.h"
#include "Player.h"
#include "GameObject.h"
class World
{

private:

	//bool backgroundsCreated = false;
	Graphics* graphics;
	//Player player;
	const HAPI_TKeyboardData& keyData;

	std::string backgroundToDraw = "BG1";

	
	std::list<GameObject*> entities;


public:
	//declaring collection of entities to be created for start of game
	GameObject* gameManager;
	GameObject* player;
	GameObject* enemy;
	GameObject* enemy2;

	World() :keyData(HAPI.GetKeyboardData()) {};

	void StartGame();
	void Update();

	GameObject* Instantiate(GameObject* gameObject, int posX, int posY);

	template <typename ObjectType>
	GameObject* Instantiate(int posX, int posY);

	void SetBackground(std::string newBackground);

	//bool GetBackgroundStatus();
	
	std::list<GameObject*> GetWorldEntities()
	{
		return entities;
	}

	void StartBattle(GameObject* collision);

	

	const HAPI_TControllerData& GetConrtollerData(const HAPI_TControllerData& registeredController)
	{
		return registeredController;
	}

	 ~World();


};


