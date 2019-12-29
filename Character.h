#pragma once
#include "Object.h"
#include "StateComponent.h"
#include "PhysicsBodyComponent.h"
#include "Collider.h"

class Character : public Object
{
protected:

	typedef Object super;

	int _hp;					//현재 체력
	float _moveSpeed;			//움직이는 속도	

public:
	Character();
	~Character();

	virtual void Init();
	virtual void Update();
	virtual void Release();

	Object* GetObject();
	void SetObject();
	void XMove();
	void YMove();
	void SetHP(int amount) { _hp = amount; };

	void Idle();
	void Death();
	void Floating();
	void Hit();
	void Ladder();
	virtual void Special1();
	virtual void Special2();


	int GetHP() { return _hp; }

};

