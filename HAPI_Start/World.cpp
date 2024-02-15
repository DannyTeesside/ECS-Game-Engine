#include "World.h"

#include "EntityMasterHeader.h"



void World::StartGame()
{
	graphics = new Graphics;
	graphics->Initialise();
	//graphics->CreateSprite("Data\\BG.png", "RoamBG");
	//graphics->CreateSprite("Data\\overworld.png", "BattleBG");
	//player.CreatePlayer(*graphics);

	//define gameManager entity first
	gameManager = new GameObject(*graphics, new GameManager, 0, 0);

	/*for (auto background : gameManager->GetComponent<GameManager>()->GetBackgrounds())
	{
		graphics->CreateSprite(background, "BG");
	}*/

	for (size_t i = 0; i < gameManager->GetComponent<GameManager>()->GetBackgrounds().size(); i++)
	{
		graphics->CreateSprite(gameManager->GetComponent<GameManager>()->GetBackgrounds()[i], "BG" + std::to_string(i+1));
	}

	
	//backgroundsCreated = true;

	//defining starting entities
	player = new GameObject(*graphics, new Player, 0, 0);
	enemy = new GameObject(*graphics, new BasicEnemy(500,300,500,500,300,500,300,300), 500, 300);
	enemy2 = new GameObject(*graphics, new BasicEnemy(600, 100, 800, 300, 800, 100, 600, 300), 600, 100);



	//adding starting entites to list
	entities.push_back(gameManager);
	entities.push_back(player);
	entities.push_back(enemy);
	entities.push_back(enemy2);


	for (GameObject* entity : entities)
	{
		entity->SetWorld(this);
		for (Component* component : entity->ReturnComponentVector())
		{
			component->SetWorld(this);
		}
	}
}

void World::Update()
{
	graphics->ClearScreen();
	graphics->DrawSprite(backgroundToDraw, 0, 0);
	const HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);
	for each (auto object in entities)
	{
		object->Update(*graphics);
	}

	if (keyData.scanCode[HK_SPACE])
	{
		gameManager->GetComponent<GameManager>()->SpawnEnemy();
		
	}
}

//GameObject* World::Instantiate(GameObject* gameObject, int posX, int posY)
//{
//	GameObject* newObject = new GameObject(*graphics, new Enemy);
//	entities.push_back(newObject);
//	return newObject;
//}


template<typename EntityType>
GameObject* World::Instantiate(int posX, int posY)
{
	GameObject* newObject = new GameObject(*graphics, new EntityType, posX, posY);
	entities.push_back(newObject);
	newObject->SetWorld(this);
	return newObject;
}
void World::SetBackground(std::string newBackground)
{
	backgroundToDraw = newBackground;
}

void World::StartBattle(GameObject* collision)
{
	gameManager->GetComponent<WorldStateMachine>()->EnterBattleState();
	for (auto entity : entities)
	{
		if (entity != player && entity != gameManager && entity != collision)
		{
			entity->SetActive(false);
		}
	}
	collision->GetComponent<EnemyStateMachine>()->EnterBattleState();

}

//bool World::GetBackgroundStatus()
//{
//	//THIS WORKS?
//	return false;
//	//BELOW RETURNS NULLPTR FOR SOME REASON. CANT FIGURE IT OUT
//	return backgroundsCreated;
//}
World::~World()
{
	//for (GameObject* entity : entities)
	//{
	//	for (Component* component : entity->ReturnComponentVector())
	//	{
	//		component->PrintComponent();
	//	}
	//}
	for (auto it = entities.begin(); it != entities.end();)
	{
		GameObject* entity = *it;

		it = entities.erase(it);

		delete entity;
	}

	delete graphics;

}
