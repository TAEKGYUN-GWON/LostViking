#pragma once
#include"Collider.h"
class ErikScript : public Collider
{
public:
	ErikScript();
	~ErikScript();
	virtual void CollisionBegin(void* obj);
	//�浹��
	virtual void CollisionPreSolve(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);  
};

