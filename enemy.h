#pragma once
#include "Object.h"
#include "PhysicsBodyComponent.h"

enum ENEMY_STATE
{
	MOVE_LEFT,
	MOVE_RIGHT,
	ATTACK_LEFT,
	ATTACK_RIGHT
};

class Enemy :	public Object
{
private:

	//bool _isLeft;
	bool _isAttack;
	float _speed;

	ENEMY_STATE _state;

	PhysicsBodyComponent* _physics;

protected:
	typedef Object super;

public:
	Enemy() {};
	~Enemy() {};

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void Move();
	void Shoot();

	void setState(ENEMY_STATE state) { _state = state; }
};

