#pragma once
#include "Enemy.h"
class BasicEnemy : public Enemy
{

public:

	BasicEnemy() {}

	BasicEnemy(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	//name = "basicEnemy";

	std::string GetTexture() override
	{
		return "Data\\sampleSprite.png";
	}
	const std::string GetName() override
	{
		return "BasicEnemy";
	}

};

