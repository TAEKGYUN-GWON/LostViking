#pragma once
#include "Object.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

class Plasma : public Object
{
private:
	PhysicsBodyComponent* _physic;

protected:

	typedef Object super;

public:
	Plasma() {};
	~Plasma() {};

	virtual void Init() override;
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
};

