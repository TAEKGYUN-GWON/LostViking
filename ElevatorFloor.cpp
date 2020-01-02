#include "stdafx.h"
#include "ElevatorFloor.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"

ElevatorFloor::ElevatorFloor()
{
}


ElevatorFloor::~ElevatorFloor()
{
}

void ElevatorFloor::Init()
{
	_pBody = AddComponent< PhysicsBodyComponent>();
	_pBody->Init(DYNAMIC, 1.f,1,0,0,1);
	
}

void ElevatorFloor::Update()
{
	_pBody->SetBodyPosition();
	super::super::Update();

}
