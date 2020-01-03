#include "stdafx.h"
#include "EXIT.h"
#include"TransformComponent.h"
#include"EXITScript.h"

EXIT::EXIT()
{
}


EXIT::~EXIT()
{
}

void EXIT::Init()
{
	_name = "EXIT";
	_tag = "EXIT";
	_trans->SetPos(892.5f, 2162.5f);
	_trans->SetScale(185,179);
	_physics = AddComponent< PhysicsBodyComponent>();
	AddComponent<EXITScript>();
	_physics->Init(STATIC, 1, 1, 0, 0, 1);
	_vikingNum = 0;

}

bool EXIT::GameEnd()
{
	if (_vikingNum != 3) return false;
	else return true;
}
