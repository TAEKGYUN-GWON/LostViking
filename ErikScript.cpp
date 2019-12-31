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

	if (to->GetName() == "LADDER")
	{
		cout << "��ٸ� �ε���" << endl; 
		me->SetLadder(true);
	}
}
	

void ErikScript::CollisionPreSolve(void * obj)
{
}

void ErikScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;

	if (to->GetName() == "LADDER")
	{
		cout << "��ٸ� ������" << endl;
		me->SetLadder(false);
	}
}
