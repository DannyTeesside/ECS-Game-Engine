#pragma once
#include <vector>
#include <string>
#include <HAPI_lib.h>

class GameObject;
class World;

class Component
{
private:

protected:
	std::string texture = "Empty";

public:
	GameObject* gameObject = nullptr;
	World* worldInstance = nullptr;
	

	//const std::string name = "enemy";
	virtual void SetTexture(std::string newTexture) { texture = newTexture; }
	virtual const std::string GetName() { return "Unnamed Object"; }
	virtual const std::string GetTag() { return " "; }
	virtual int ReturnComponentAmount() {return 0;}
	virtual Component* ReturnComponentVector(int componentIndex) { return nullptr; }
	virtual void PrintComponent() {}
	virtual void Update() {}

	void SetWorld(World* world)
	{
		worldInstance = world;
	}

	virtual std::string GetTexture()
	{
		return texture;
	}

	/*void SetTexture(std::string newTexture)
	{
		texture = newTexture;
	}*/
	

	virtual ~Component() = default;

};

