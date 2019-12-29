#pragma once
#include "Component.h"
class Collider : public Component
{

public:
	Collider();
	~Collider();
	virtual void CollisionBegin(void* obj) { };
	virtual void CollisionPreSolve(void* obj) { };
	virtual void CollisionEnd(void* obj) { };
	
};

