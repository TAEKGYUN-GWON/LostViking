#include "stdafx.h"
#include "ErikScript.h"
#include "Object.h"
#include "Character.h"

ErikScript::ErikScript()
{
}


ErikScript::~ErikScript()
{
}

void ErikScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;

	if (to->GetName() == "Ladder1")
	{
		cout << "»ç´Ù¸® ºÎµúÈû" << endl; 
		me->SetLadder(true);
		//me->SetGravity(0.1f);
	}
}
	

void ErikScript::CollisionPreSolve(void * obj)
{
}

void ErikScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;

	if (to->GetName() == "Ladder1")
	{
		cout << "»ç´Ù¸® ¶³¾îÁü" << endl;
		me->SetLadder(false);  
		 me->SetGravity(1);
	}
}
