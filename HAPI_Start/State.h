#pragma once

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <HAPI_lib.h>

class State
{
public:
	virtual void Enter(){}
	virtual void Tick(float deltaTime) {}
	virtual void Exit() {}


	virtual ~State() {}
};

#endif




