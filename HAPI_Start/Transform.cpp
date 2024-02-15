#include "Transform.h"

void Transform::MoveTowards(Vector2 targetPosition, int speed)
{
	Vector2 direction = { targetPosition.x - position.x, targetPosition.y - position.y };
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distance > 0)
	{
		direction.x /= distance;
		direction.y /= distance;
	}

	position.x += direction.x * speed;
	position.y += direction.y * speed;

}

void Transform::MoveTowards()
{
	position.x--;
}
