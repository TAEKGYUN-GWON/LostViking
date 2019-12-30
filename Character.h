#pragma once
#include "Object.h"
#include "StateComponent.h"
#include "PhysicsBodyComponent.h"
#include "Collider.h"

class Character : public Object
{
protected:

	typedef Object super;

	StateComponent* _state;
	PhysicsBodyComponent* _physics;

	int _hp;					//현재 체력
	float _moveSpeedX, _moveSpeedY;			//움직이는 속도	

public:
	Character();
	~Character();

	virtual void Init();
	virtual void Update();
	virtual void Release();

	void KeyControl();

	void XMove(float moveX);
	void YMove(float moveY);
	void SetHP(int amount) { _hp = amount; };

	void Idle(string key);
	void Death(string key);
	void Floating(string key);
	void Hit(string key);
	void Move(string key);
	void Ladder(string key);

	void Ladder();

	virtual void Special1() {};
	virtual void Special2() {};




	int GetHP() { return _hp; }

};

