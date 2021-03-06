#pragma once
#include "Object.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

class Computer : public Object
{
private:
	PhysicsBodyComponent* _physic;
	int hp = 14;
protected:
	typedef Object super;
public:
	Computer() {};
	~Computer() {};

	virtual void Init();
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
	virtual void Atacked() { --hp; };
};

