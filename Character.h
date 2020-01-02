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

	Vector2 _lastPos;

	int count;							//
	int _hp;							//현재 체력
	float _moveSpeedX, _moveSpeedY;		//움직이는 속도	
	float _friction;

	float mass;

	bool _isLadder, _isLaddering;		//사다리 충돌중 판단
	bool _isGround;						//땅입니까?
	bool _isFloating;					//떨어지고 있습니까
	bool _isPush;						//벽을 밀고있습니까
	bool _isDead;						//야,야야,죽었냐?
	bool _isActive;						//오브젝트와의 상호작용

public:
	Character();
	~Character();

	virtual void Init();
	virtual void Update();
	virtual void Release();

	void KeyControl();
	void PosCorrection();

	void SetState(Object_STATE state) { _state->SetState(state); }

	void SetHP(int amount) { _hp = amount; };
	int GetHP() { return _hp; }


	void SetLadder(bool ladder) { _isLadder = ladder; }
	void SetPush(bool push) { _isPush = push; }
	void DeadSetting() { _isDead = true; }

	bool GetLadder() { return _isLadder; };

	void SetGravity(float gravity) { _physics->GetBody()->SetGravityScale(gravity); }

	string GetTag() { return _tag; }

	void Idle(string key);
	void Death(string key);
	void Floating(string key);
	void Hit(string key);
	void Move(string key);
	void Ladder(string key);

	virtual void Special1() {};
	virtual void Special2() {};



};

