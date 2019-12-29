#include "stdafx.h"
#include "Character.h"


Character::Character()
{

}

Character::~Character()
{

}

void Character::Init()
{
	_hp = 3;
	_moveSpeed = 2.f;

	_tag = "Player";

	AddComponent<PhysicsBodyComponent>()->Init(DYNAMIC);
	AddComponent<StateComponent>();

}

void Character::Update()
{
	super::Update();
}

void Character::Release()
{
	super::Release();
}
