#pragma once
#include "Collider.h"
class bulletScript : public Collider
{

public:
	virtual void CollisionBegin(void* obj) override;
	//�浹��
	virtual void CollisionPreSolve(void* obj) override;
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj) override;
};

