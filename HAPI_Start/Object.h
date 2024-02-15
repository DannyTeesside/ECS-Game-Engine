#pragma once

class Transform;

class Object
{
private:



public:
	Transform* transform;
	

	Object();
	virtual ~Object();

	void Destroy(Object object);

};

