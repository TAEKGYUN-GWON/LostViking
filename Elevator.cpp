#include "stdafx.h"
#include "Elevator.h"
#include"GraphicComponent.h"
#include"TransformComponent.h"
#include"ElevatorScript.h"
#include"PhysicsBodyComponent.h"
Elevator::Elevator()
{
}


Elevator::~Elevator()
{
}

void Elevator::Init()
{
	GRAPHICMANAGER->AddImage("Elevator", L"img/background/Elevator.png");
	_graphic->SetImgName("Elevator");
	_trans->SetScale(_graphic->GetGraphic()->GetWidth(), _graphic->GetGraphic()->GetHeight());
	_trans->SetPos(2804, 675.5f);
	isOn = false;
	isUp = up;
	AddComponent<ElevatorScript>();
	_pBody = AddComponent<PhysicsBodyComponent>();
	_pBody->Init(KINEMATIC, 1.f);
	_tag = "Elevator";
	_name = "Elevator";
}

void Elevator::Update()
{
	super::super::Update();
	_trans->SetPos(_pBody->GetBodyPosition());
}
