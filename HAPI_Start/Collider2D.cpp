#include "Collider2D.h"


bool Collider2D::IsColliding(const Collider2D& other)
{
	return (gameObject->transform->position.x < other.gameObject->transform->position.x + other.gameObject->GetRectRight() &&
		gameObject->transform->position.x + gameObject->GetRectRight() > other.gameObject->transform->position.x &&
		gameObject->transform->position.y < other.gameObject->transform->position.y + other.gameObject->GetRectBottom() &&
		gameObject->transform->position.y + gameObject->GetRectBottom() > other.gameObject->transform->position.y);
}