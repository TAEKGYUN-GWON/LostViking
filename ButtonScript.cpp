#include "stdafx.h"
#include "ButtonScript.h"
#include "Button.h"

void ButtonScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Button* me = (Button*)_object;

	if (to->GetTag() == "Player")
	{
		me->SetCollision(true);
	}
	if (to->GetName() == "Arrow")
	{
		me->SetCollision(true);
		me->SetIsActive(false);
		to->SetIsActive(false);
	}
}

void ButtonScript::CollisionPreSolve(void * obj)
{
}

void ButtonScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Button* me = (Button*)_object;

	if (to->GetTag() == "Player")
	{
		me->SetCollision(false);
	}
}
