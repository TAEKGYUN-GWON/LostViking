#include "stdafx.h"
#include "script.h"
#include "PhysicsBodyComponent.h"
#include"Object.h"

script::script()
{
}


script::~script()
{
}

void script::CollisionBegin(void * obj)
{
	//cout << "Ȯ��" << endl;
	//_object->SetIsActive(false);
	//_object->GetTrans()->SetPos(WINSIZEX/2, 200);
}

void script::CollisionPreSolve(void * obj)
{
	//cout << "Ȯ��" << endl;
}

void script::CollisionEnd(void * obj)
{
	cout << "������" << endl;
}
