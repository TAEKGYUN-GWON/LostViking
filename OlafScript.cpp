#include "stdafx.h"
#include "OlafScript.h"
#include "Object.h"
#include "Olaf.h"
#include"TransformComponent.h"

OlafScript::OlafScript()
{
}


OlafScript::~OlafScript()
{
}

void OlafScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Olaf* me = (Olaf*)_object;


	if (to->GetName() == "Floor" || to->GetName() == "Elevator")
	{
		cout << "¹Ù´ÚÀÌ¶û ´êÀ½" << endl;
		me->SetGround(true);
	}

	if (to->GetName() == "Ladder1" ||
		to->GetName() == "Ladder2" ||
		to->GetName() == "Ladder3" ||
		to->GetName() == "Ladder4" ||
		to->GetName() == "Ladder5" ||
		to->GetName() == "Ladder6")
	{
		cout << "»ç´Ù¸® ºÎµúÈû" << endl;
		me->SetLadder(true);
		me->Correction(to->GetTrans()->GetPos());
		//me->SetGravity(0.1f);
	}
	if (to->GetName() == "Barrier")
	{
		cout << "º®ÀÌ¶û ´êÀ½" << endl;
		me->SetPush(true);
	}

	//ÀûÀÇ ÃÑ¾ËÀÌ¶û ´ê´Â°Å Ã¼Å©
	//ÅÂ±× Bullet ÀÌ¶ó ¸ðµç ÃÑ¾ËÀÓ
	if (to->GetTag() == "Bullet")
	{
		//ÃÑ¾ËÀ» Áö¿ì°í
		//ÇÇ¸¦ ±ð´Â´Ù
		cout << "ÃÑ¾ËÀÌ¶û ´êÀ½" << endl;
		to->SetIsActive(false);
		me->SetHP(-1);
		cout << me->GetHP() << endl;
	}
}


void OlafScript::CollisionPreSolve(void * obj)
{
	Object* to = (Object*)obj;
	Olaf* me = (Olaf*)_object;
	if (to->GetTag() == "Ladder")
	{
		cout << "´ê°íÀÌµû" << endl;
	}
}

void OlafScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Olaf* me = (Olaf*)_object;

	if (to->GetName() == "Floor")
	{
		cout << "¹Ù´ÚÀÌ¶û ¶³¾îÁü" << endl;
		me->SetGround(false);
	}
	if (to->GetName() == "Ladder1" ||
		to->GetName() == "Ladder2" ||
		to->GetName() == "Ladder3" ||
		to->GetName() == "Ladder4" ||
		to->GetName() == "Ladder5" ||
		to->GetName() == "Ladder6")
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
