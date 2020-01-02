#pragma once
#include "Collider.h"
class bulletScript : public Collider
{

public:
	virtual void CollisionBegin(void* obj) override;
	//충돌중
	virtual void CollisionPreSolve(void* obj) override;
	//충돌 끝난 시점
	virtual void CollisionEnd(void* obj) override;
};

