#pragma once
#include"Collider.h"
class ErikScript : public Collider
{
public:
	ErikScript();
	~ErikScript();
	virtual void CollisionBegin(void* obj);
	//충돌중
	virtual void CollisionPreSolve(void* obj);
	//충돌 끝난 시점
	virtual void CollisionEnd(void* obj);  
};

