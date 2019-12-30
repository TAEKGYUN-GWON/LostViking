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
	_moveSpeedX = 2.f;
	_moveSpeedY = 1.f;

	_tag = "Player";

	_physics = AddComponent<PhysicsBodyComponent>();
	_physics->Init(DYNAMIC);

	_state =  AddComponent<StateComponent>();

}

void Character::Update()
{
	super::Update();

	KeyControl();
}

void Character::Release()
{
	super::Release();
}

void Character::KeyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		XMove(-_moveSpeedX);
		_state->SetState(LEFT_IDLE);
		GRAPHICMANAGER->DrawTextD2D(Vector2(50, 300), L"좌클릭", 20);
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isToggleKey(VK_LEFT))
	{
		XMove(-_moveSpeedX);
		_state->SetState(LEFT_MOVE);
		//Move(이미지이름);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		XMove(_moveSpeedX);
		_state->SetState(RIGHT_IDLE);
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		XMove(_moveSpeedX);
		_state->SetState(RIGHT_MOVE);
		//Move(이미지이름);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		YMove(-_moveSpeedY);
		Ladder();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		YMove(_moveSpeedY);
	}

}

void Character::XMove(float moveX)
{
	_trans->SetPos(_trans->GetPos().x + moveX, _trans->GetPos().y);
}

void Character::YMove(float moveY)
{
	_trans->SetPos(_trans->GetPos().x, _trans->GetPos().y + moveY);
}

void Character::Idle(string key)
{
	_graphic->SetImgName(key);
}

void Character::Death(string key)
{
	_graphic->SetImgName(key);
}

void Character::Floating(string key)
{
	_graphic->SetImgName(key);
}

void Character::Hit(string key)
{
	_graphic->SetImgName(key);
}

void Character::Ladder(string key)
{
	_graphic->SetImgName(key);
}

void Character::Move(string key)
{
	_graphic->SetImgName(key);
}

void Character::Ladder()
{

}