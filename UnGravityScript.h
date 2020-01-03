#pragma once
#include "Collider.h"
class UnGravityScript :
	public Collider
{
	bool on=false;
public:
	UnGravityScript();
	~UnGravityScript();
	//충돌한 직후
	virtual void CollisionBegin(void* obj);
	//충돌 끝난 시점
	virtual void CollisionEnd(void* obj);
	void SetOn(bool on) { this->on = on; }
	bool GetOn() { return on; }
};

