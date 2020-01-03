#include "stdafx.h"
#include "ItemScript.h"
#include "Item.h"


void ItemScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Item* me = (Item*)_object;

	if (to->GetTag() == "Player")
	{
		me->SetColliosion(true);
		
	}

}

void ItemScript::CollisionPreSolve(void * obj)
{
}

void ItemScript::CollisionEnd(void * obj)
{
}
