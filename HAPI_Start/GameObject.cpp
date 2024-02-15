#include "GameObject.h"
#include "World.h"

GameObject::GameObject()
{
	
	transform->position.x = 1 + (rand() % 300);
	transform->position.y = 1 + (rand() % 300);
}

GameObject::GameObject(Graphics& graphics, Component* component, int posX, int posY)
{
	srand(time(0));
	transform->position.x = posX;
	transform->position.y = posY;
	AddComponent(component);
	AddComponentVector(component);
	component->gameObject = this;
	SetName(component->GetName());
	SetTag(component->GetTag());
	texture = component->GetTexture();
	CreateObjectSprite(graphics, component->GetName());
	std::cout << component->GetName() << std::endl;
	
}
void GameObject::CreateObjectSprite(Graphics& graphics, const std::string name)
{
	graphics.CreateSprite(texture, name);
}
void GameObject::DrawObject(Graphics& graphics, std::string name)
{
	graphics.DrawSprite(name, transform->position.x, transform->position.y);
	rectLeft = graphics.GetRectLeft();
	rectRight = graphics.GetRectRight();
	rectTop = graphics.GetRectTop();
	rectBottom = graphics.GetRectBottom();

	/*if (transform->position.x > (graphics.GetScreenWidth() / 2) - 100 && transform->position.x < (graphics.GetScreenWidth() / 2) + 100 && transform->position.y >(graphics.GetScreenHeight() / 2) - 100 && transform->position.y < (graphics.GetScreenHeight() / 2) + 100)
	{
		HAPI.SetControllerRumble(0, 30000, 30000);
	}
	else
	{
		HAPI.SetControllerRumble(0, 0, 0);
	}*/
}
void GameObject::Update(Graphics& graphics)
{
	if (isActive)
	{
		for (Component* component : components)
		{
			component->Update();

		}
		DrawObject(graphics, name);
	}
	
}
void GameObject::AddComponent(Component* component)
{
	components.push_back(component);
}

void GameObject::AddComponentVector(Component* sourceComponent)
{
	for (size_t i = 0; i < sourceComponent->ReturnComponentAmount(); i++)
	{
		sourceComponent->ReturnComponentVector(i)->gameObject = this;
		AddComponent(sourceComponent->ReturnComponentVector(i));
	}
}
void GameObject::CloneComponents(GameObject* sourceGameObject)
{
	for (size_t i = 0; i < sourceGameObject->ReturnComponentAmount(); i++)
	{
		AddComponent(sourceGameObject->ReturnComponentVector(i));
	}
}

GameObject* GameObject::CloneObject()
{
	return new GameObject(*this);
}

bool GameObject::DetectCollisions(const std::string otherTag)
{
	for (auto entity : worldInstance->GetWorldEntities())
	{
		if (entity->GetName() != GetName() && entity->GetTag() == otherTag)
		{
			if (GetComponent<Collider2D>()->IsColliding(*entity->GetComponent<Collider2D>()))
			{
				SetCollidingObject(entity);
				std::cout << entity->GetName();
				return true;
			}
		}
	}
	return false;
}



GameObject::~GameObject()
{
	//delete transform;
	//delete gameObject;
	for each (Component* component in components)
	{
		
		delete component;
	}
	
}

