#include "stdafx.h"
#include "ElevatorScript.h"
#include"Object.h"
#include"Elevator.h"
#include"PhysicsBodyComponent.h"
ElevatorScript::ElevatorScript()
{
}


ElevatorScript::~ElevatorScript()
{
}

void ElevatorScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Elevator* me = (Elevator*)_object;

	if (to->GetTag() == "Player")
	{
		me->SetIsOn(true);
		cout << "�鰨" << endl;
	}
	if (to->GetName() == "ElevatorTop")
	{
		cout << "ž" << endl;
		me->SetElevatorPos(top);
		me->SetStop(true);
	}

	if (to->GetName() == "ElevatorMiddle")
	{
		cout << "�̵�" << endl;
		if(me->GetIsUp()==down) me->SetStop(true);
	}

	if (to->GetName() == "ElevatorBottom")
	{
		cout << "����" << endl;
		me->SetElevatorPos(bottom);
		me->SetStop(true);
	}

}

void ElevatorScript::CollisionPreSolve(void * obj)
{
}

void ElevatorScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Elevator* me = (Elevator*)_object;

	if (to->GetName() == "Player") me->SetIsOn(false);


	if (to->GetName() == "ElevatorMiddle")
	{
		if (me->GetIsUp()==up) me->SetStop(true);
	}


}
