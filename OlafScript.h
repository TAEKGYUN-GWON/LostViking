#pragma once
#include"Collider.h"
class OlafScript : public Collider
{
public:
	OlafScript();
	~OlafScript();

	virtual void CollisionBegin(void* obj);
	//�浹��
	virtual void CollisionPreSolve(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);
};

