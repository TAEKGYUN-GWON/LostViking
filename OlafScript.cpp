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
		cout << "�ٴ��̶� ����" << endl;
		me->SetGround(true);
	}

	if (to->GetName() == "Ladder1" ||
		to->GetName() == "Ladder2" ||
		to->GetName() == "Ladder3" ||
		to->GetName() == "Ladder4" ||
		to->GetName() == "Ladder5" ||
		to->GetName() == "Ladder6")
	{
		cout << "��ٸ� �ε���" << endl;
		me->SetLadder(true);
		me->Correction(to->GetTrans()->GetPos());
		//me->SetGravity(0.1f);
	}
	if (to->GetName() == "Barrier")
	{
		cout << "���̶� ����" << endl;
		me->SetPush(true);
	}

	//���� �Ѿ��̶� ��°� üũ
	//�±� Bullet �̶� ��� �Ѿ���
	if (to->GetTag() == "Bullet")
	{
		//�Ѿ��� �����
		//�Ǹ� ��´�
		cout << "�Ѿ��̶� ����" << endl;
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
		cout << "����̵�" << endl;
	}
}

void OlafScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Olaf* me = (Olaf*)_object;

	if (to->GetName() == "Floor")
	{
		cout << "�ٴ��̶� ������" << endl;
		me->SetGround(false);
	}
	if (to->GetName() == "Ladder1" ||
		to->GetName() == "Ladder2" ||
		to->GetName() == "Ladder3" ||
		to->GetName() == "Ladder4" ||
		to->GetName() == "Ladder5" ||
		to->GetName() == "Ladder6")
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
