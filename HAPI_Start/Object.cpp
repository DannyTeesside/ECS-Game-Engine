#include "Object.h"
#include "Transform.h"

Object::Object()
{
	transform = new Transform;
}

Object::~Object()
{
	delete transform;
}

void Object::Destroy(Object object)
{

}
