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


	if (to->GetName() == "Floor")
	{
		cout << "¹Ù´ÚÀÌ¶û ´êÀ½" << endl;
		me->SetGround(true);
	}
	if (to->GetName() == "Ladder1")
	{
		cout << "»ç´Ù¸® ºÎµúÈû" << endl; 
		me->SetLadder(true);
		//me->SetGravity(0.1f);
	}
	if (to->GetName() == "Barrier")
	{
		cout << "º®ÀÌ¶û ´êÀ½" << endl;
		me->SetPush(true);
	}
}
	

void ErikScript::CollisionPreSolve(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;
	if (to->GetName() == "Ladder1")
	{
		cout << "´ê°íÀÌµû" << endl;
	}
}

void ErikScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;

	if (to->GetName() == "Floor")
	{
		cout << "¹Ù´ÚÀÌ¶û ¶³¾îÁü" << endl;
		me->SetGround(false);
	}
	if (to->GetName() == "Ladder1")
	{
		cout << "»ç´Ù¸® ¶³¾îÁü" << endl;
		me->SetLadder(false);
		 me->SetGravity(1);
	}
	if (to->GetName() == "Barrier")
	{
		cout << "º®ÀÌ¶û ¶³¾îÁü " << endl;
		me->SetPush(false);
	}
}
