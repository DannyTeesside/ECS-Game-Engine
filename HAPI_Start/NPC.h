#pragma once
#include "ComponentsMasterHeader.h"

class NPC : public Component
{
private:
	Collider2D* collider = new Collider2D;

	std::vector<Component*> componentsToAdd = {
		collider,

	};

public:
	NPC()
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

	~NPC();
};

