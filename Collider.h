#pragma once
#include "Component.h"
class Collider : public Component
{
public:
	Collider();
	~Collider();
	virtual void CollisionBegin(Object* obj) {};
	virtual void CollisionPreSolve(Object* obj) {};
	virtual void CollisionEnd(Object* obj) {};
	
};

