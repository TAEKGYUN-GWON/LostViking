#include "stdafx.h"
#include "EXITScript.h"
#include"EXIT.h"
#include"Object.h"
EXITScript::EXITScript()
{
}


EXITScript::~EXITScript()
{
}

void EXITScript::CollisionBegin(void * obj)
{
	EXIT* me = (EXIT*)_object;
	Object* to = (Object*)obj;

	if (to->GetTag() == "Player1") me->CountUp();

}

void EXITScript::CollisionEnd(void * obj)
{
	EXIT* me = (EXIT*)_object;
	Object* to = (Object*)obj;

	if (to->GetTag() == "Player1") me->CountDown();
}
