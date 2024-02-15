#pragma once
#include "Component.h"
#include <iostream>

struct Vector2
{
	float x = 0;
	float y = 0;
};


class Transform : public Component
{
private:

public:
	Vector2 position;
	Vector2 scale;
	Vector2 rotation;

	void PrintComponent() override
	{
		std::cout << "Transform" << std::endl;
	}

	void MoveTowards(Vector2 target, int speed);
	void MoveTowards();


};

