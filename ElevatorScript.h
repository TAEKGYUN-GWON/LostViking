#pragma once
#include "Collider.h"
class ElevatorScript :	public Collider
{
public:
	ElevatorScript();
	~ElevatorScript();
	virtual void CollisionBegin(void* obj);
	//�浹��
	virtual void CollisionPreSolve(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);
};

