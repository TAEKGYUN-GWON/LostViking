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

	int count;							//
	int _hp;							//현재 체력
	float _moveSpeedX, _moveSpeedY;		//움직이는 속도	
	float _friction;

	float mass;

	bool _isLadder;						//사다리 충돌중 판단
	bool _isDead;						//야,야야,죽었냐?

public:
	Character();
	~Character();

	virtual void Init();
	virtual void Update();
	virtual void Release();

	void KeyControl();

	void SetState(Object_STATE state) { _state->SetState(state); }
	StateComponent* GetState() { return _state; }

	void SetHP(int amount) { _hp = amount; };
	int GetHP() { return _hp; }


	void SetLadder(bool ladder) { _isLadder = ladder; }
	bool GetLadder() { return _isLadder; };

	void SetGravity(float gravity) { _physics->GetBody()->SetGravityScale(gravity); }

	string GetTag() { return _tag; }

	void ChangeImage(string key); //문지예가 만듦

	void Ladder();
	virtual void Special1() {};
	virtual void Special2() {};





};

