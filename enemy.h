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

	bool _isAttack;
	float _speed;
	float _timer;
	float _fireCount;
	int _direction; //-1 왼, 1오



	ENEMY_STATE _state;

	PhysicsBodyComponent* _physics;

protected:
	typedef Object super;

public:
	Enemy() {};
	~Enemy() {};

	void Init(Vector2 pos, string image, float speed, ENEMY_STATE state, bool isattack, float timer, int direction);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void Move();
	void Attack();
	bool IsFire();//트루가 되면 에너미 매니저에서 총을 쏴주는 애

	//setter
	void SetState(ENEMY_STATE state) { this->_state = state; }
	void SetAttack(bool isattack) { _isAttack = isattack; }

	//getter
	int GetDirection() { return _direction; }
	ENEMY_STATE GetState() { return _state; }
	virtual inline PhysicsBodyComponent* GetPhysics() { return _physics; }
	//virtual inline PhysicsBodyComponent* GetPhysics() { return _physics; }
	//virtual inline TransformComponent* GetTrans() { return _trans; }
	bool GetAttack() { return _isAttack; }
};

