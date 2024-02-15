#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iostream>

class Collider2D : public Component
{
private:
	bool isTrigger = false;

public:
	Collider2D() { GetTexture(); }
	void PrintComponent() override
	{
		std::cout << "Collider2D" << std::endl;
	}
	void SetTexture(std::string newTexture) override
	{
		texture = newTexture;
	}

	bool IsColliding(const Collider2D& other);

	void OnTriggerStay(const Collider2D& other)
	{

	}

	void OnTriggerExit(const Collider2D& other)
	{

	}


	void SetTriggerStatus(bool value)
	{
		isTrigger = value;
	}

	bool GetTriggerStatus()
	{
		return isTrigger;
	}




};

