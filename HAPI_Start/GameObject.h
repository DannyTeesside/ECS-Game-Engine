#pragma once
#include "Object.h"
#include <vector>
#include "ComponentsMasterHeader.h"
#include <iostream>
#include "Graphics.h"

class GameObject : public Object
{

	//reordered public and private due to wanting transform variable to be public but needed it initialised first before adding it to components vector
private:

	bool isActive = true;

	std::string texture;
	std::string name;

	std::string tag;

	int rectLeft;
	int rectRight;
	int rectTop;
	int rectBottom;

	GameObject* collidingObject;

	std::vector<Component*> components =
	{

	};

	
public:

	World* worldInstance = nullptr;


	GameObject();
	GameObject(const std::string name) :name(name) { }
	GameObject(Graphics& graphics, Component* component, int posX, int posY);

	void SetWorld(World* world)
	{
		worldInstance = world;
	}

	bool DetectCollisions(const std::string otherTag);

	void SetActive(bool value)
	{
		isActive = value;
	}

	void SetCollidingObject(GameObject* otherObject)
	{
		collidingObject = otherObject;
	}

	GameObject* GetCollidingObject()
	{
		return collidingObject;
	}



	const std::string GetName()
	{
		return name;
	}

	void SetName(std::string objectName)
	{
		name = objectName;
	}

	const std::string GetTag()
	{
		return tag;
	}

	void SetTag(std::string objectTag)
	{
		tag = objectTag;
	}

	int GetRectRight()
	{
		return rectRight;
	}

	int GetRectLeft()
	{
		return rectLeft;
	}

	int GetRectTop()
	{
		return rectTop;
	}

	int GetRectBottom()
	{
		return rectBottom;
	}

	void CreateObjectSprite(Graphics& graphics, const std::string name);

	void DrawObject(Graphics& graphics, const std::string name);

	void Update(Graphics& graphics);
	
	template <typename T>
	T* GetComponent() const
	{
		if (components.size() == 0)
		{
			std::cout << "No Components" << std::endl;
			return nullptr;
		}
		else
		{
			for (Component* component : components)
			{
				if (dynamic_cast<T*>(component) != nullptr)
				{
					return static_cast <T*>(component);
				}
			}
		}
		
		
		return nullptr;

	}

	void AddComponent(Component* component);

	void AddComponentVector(Component* sourceComponent);

	void CloneComponents(GameObject* sourceGameObject);
	GameObject* CloneObject();

	int ReturnComponentAmount()
	{
		return components.size();
	}

	std::vector<Component*> ReturnComponentVector()
	{
		return components;

	}

	Component* ReturnComponentVector(int componentIndex)
	{
		return components[componentIndex];
		
	}

	 ~GameObject();

};

