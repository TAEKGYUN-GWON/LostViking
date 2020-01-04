#include "stdafx.h"
#include "BombScript.h"
#include "Bomb.h"

void BombScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Bomb* me = (Bomb*)_object;

	if (to->GetTag() == "Computer" || to->GetTag() == "Player1")
	{
		me->SetCollision(true);
	}
}

void BombScript::CollisionPreSolve(void * obj)
{
}

void BombScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Bomb* me = (Bomb*)_object;

	if (to->GetTag() == "Computer" || to->GetTag() == "Player1")
	{
		me->SetCollision(false);
	}
}
