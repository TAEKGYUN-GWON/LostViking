#pragma once
#include "Collider.h"

class ButtonScript : public Collider
{
public:
	virtual void CollisionBegin(void* obj) override;
	virtual void CollisionPreSolve(void* obj) override;
	virtual void CollisionEnd(void* obj) override;
};

