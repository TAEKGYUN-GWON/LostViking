#pragma once
#include "Object.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

class RedgunTower : public Object
{
private:
	float _count;
	PhysicsBodyComponent* _physic;
protected:
	typedef Object super;
public:
	RedgunTower() {};
	~RedgunTower() {};

	virtual void Init();
	virtual void Init(Vector2 pos, int frameY);
	virtual void Release() override;
	virtual void Update() override;
	bool IsBulletFire();
};

