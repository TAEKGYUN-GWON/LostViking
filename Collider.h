#pragma once
#include "Component.h"

class Collider : public Component
{

public:
	Collider();
	~Collider();
	//�浹�� ����
	virtual void CollisionBegin(void* obj) { };
	//�浹��
	virtual void CollisionPreSolve(void* obj) { };
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj) { };
	
};

