#pragma once
#include "Collider.h"
class UnGravityScript :
	public Collider
{
public:
	UnGravityScript();
	~UnGravityScript();
	//�浹�� ����
	virtual void CollisionBegin(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);
};

