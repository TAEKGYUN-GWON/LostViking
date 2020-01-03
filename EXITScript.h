#pragma once
#include "Collider.h"
class EXITScript : public Collider
{
public:
	EXITScript();
	~EXITScript();
	//충돌한 직후
	virtual void CollisionBegin(void* obj);
	//충돌 끝난 시점
	virtual void CollisionEnd(void* obj);
};

