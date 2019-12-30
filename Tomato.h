#pragma once
#include "Item.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

class Tomato : public Item
{
private:
	PhysicsBodyComponent* _physic;

protected:
	typedef Item super;
public:
	virtual void Init();
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
};

