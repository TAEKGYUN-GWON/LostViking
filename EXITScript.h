#pragma once
#include "Collider.h"
class EXITScript : public Collider
{
public:
	EXITScript();
	~EXITScript();
	//�浹�� ����
	virtual void CollisionBegin(void* obj);
	//�浹 ���� ����
	virtual void CollisionEnd(void* obj);
};

