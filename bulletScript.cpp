#include "stdafx.h"
#include "bulletScript.h"
#include "Bullet.h"
#include "Character.h"
#include "Computer.h"

void bulletScript::CollisionBegin(void * obj)
{
	Object* to = (Object*) obj;
	Bullet* me = (Bullet*)_object;

	if (to->GetTag() == "Player")
	{
		Character* b = (Character*)obj;
		b->SetHP(-1);
	}
	if (to->GetTag() == "Item" || to->GetName() == "Barrier" || to->GetTag() == "Gate"||to->GetTag()=="Enemy")
	{
		me->SetIsActive(false);
	}
	if (to->GetName() == "Computer")
	{
		Computer* b = (Computer*)to;
		b->Atacked();
		me->SetIsActive(false);
	}
}

void bulletScript::CollisionPreSolve(void * obj)
{
}

void bulletScript::CollisionEnd(void * obj)
{
}
