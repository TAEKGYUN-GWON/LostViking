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
		cout << "�ٴ��̶� ����" << endl;
		me->SetGround(true);
	}
	if (to->GetName() == "Ladder1")
	{
		cout << "��ٸ� �ε���" << endl; 
		me->SetLadder(true);
		//me->SetGravity(0.1f);
	}
	if (to->GetName() == "Barrier")
	{
		cout << "���̶� ����" << endl;
		me->SetPush(true);
	}
}
	

void ErikScript::CollisionPreSolve(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;
	if (to->GetName() == "Ladder1")
	{
		cout << "����̵�" << endl;
	}
}

void ErikScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Character* me = (Character*)_object;

	if (to->GetName() == "Floor")
	{
		cout << "�ٴ��̶� ������" << endl;
		me->SetGround(false);
	}
	if (to->GetName() == "Ladder1")
	{
		cout << "��ٸ� ������" << endl;
		me->SetLadder(false);
		 me->SetGravity(1);
	}
	if (to->GetName() == "Barrier")
	{
		cout << "���̶� ������ " << endl;
		me->SetPush(false);
	}
}
