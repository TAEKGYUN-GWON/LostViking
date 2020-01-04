#pragma once
#include"Player.h"
#include"Collider.h"
class PlayerScript : public Collider
{
private:
public:
	PlayerScript();
	~PlayerScript();
	virtual void CollisionBegin(void* obj);
	virtual void CollisionPreSolve(void* obj);
	virtual void CollisionEnd(void* obj);
};

