#pragma once
#include "Collider.h"
class UnGravityScript :
	public Collider
{
	bool on=false;
public:
	UnGravityScript();
	~UnGravityScript();
	//�浹�� ����
	virtual void CollisionBegin(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);
	void SetOn(bool on) { this->on = on; }
	bool GetOn() { return on; }
};

