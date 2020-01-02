#pragma once
#include "Object.h"

class PhysicsBodyComponent;

class Bullet : public Object
{
private:
	typedef Object super;

	PhysicsBodyComponent* _physics;
	float _speed;

public:
	void Init(string imgKey, string tag, string name);
	virtual void Update();

	void Fire(Vector2 pos, float angle, float speed);
	void Move();
};

