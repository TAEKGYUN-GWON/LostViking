#include "stdafx.h"
#include "bulletScript.h"
#include "Bullet.h"
#include "Character.h"

void bulletScript::CollisionBegin(void * obj)
{
	Object* to = (Object*) obj;
	Bullet* me = (Bullet*)_object;

	if (to->GetTag() == "Item" || to->GetName() == "Barrier" || to->GetTag() == "Shield")
	{
		me->SetIsActive(false);
	}
	if (to->GetTag() == "Player")
	{
		Character* b = (Character*)obj;

		me->SetIsActive(false);
		b->SetHP(-1);
	}
}

void bulletScript::CollisionPreSolve(void * obj)
{
}

void bulletScript::CollisionEnd(void * obj)
{
}
