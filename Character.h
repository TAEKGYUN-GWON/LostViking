#pragma once
#include "Object.h"
#include "StateComponent.h"
#include "PhysicsBodyComponent.h"

class Character : public Object
{
protected:

	typedef Object super;

	StateComponent* _state;	
	PhysicsBodyComponent* _physics;

	int upPower = 130;

	int _hp;							//현재 체력
	float _moveSpeedX, _moveSpeedY;		//움직이는 속도	
	float _friction;

	float mass;

	bool _isLadder;						//사다리 충돌중 판단



public:
	Character();
	~Character();

	virtual void Init();
	virtual void Update();
	virtual void Release();

	void KeyControl();

	void SetState(Object_STATE state) { _state->SetState(state); }

	void SetHP(int amount) { _hp = amount; };
	int GetHP() { return _hp; }

	void SetLadder(bool ladder) { _isLadder = ladder; }
	bool GetLadder() { return _isLadder; };

	void SetGravity(float gravity) { _physics->GetBody()->SetGravityScale(gravity); }

	string GetTag() { return _tag; }

	void Idle(string key);
	void Death(string key);
	void Floating(string key);
	void Hit(string key);
	void Move(string key);
	void Ladder(string key);

	void Ladder();
	virtual void Special1() {};
	virtual void Special2() {};



};

