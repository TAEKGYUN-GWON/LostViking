#pragma once
#include"Collider.h"
class script : public Collider
{
public:
	script();
	~script();
	virtual void CollisionBegin(void* obj);
	virtual void CollisionPreSolve(void* obj);
	virtual void CollisionEnd(void* obj);
};

