#pragma once
#include "Collider.h"
class GateScript :	public Collider
{
public:
	GateScript();
	~GateScript();

	virtual void CollisionBegin(void* obj);
	//�浹��
	virtual void CollisionPreSolve(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);

};

