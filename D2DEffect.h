#pragma once
#include "Object.h"

class PhysicsBodyComponent;

class D2DEffect : public Object
{
private:
	typedef Object super;

	PhysicsBodyComponent* _physics;

public:
	void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
};

