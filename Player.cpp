#include "stdafx.h"
#include "Player.h"
#include "PhysicsBodyComponent.h"
#include "GraphicComponent.h"
Player::Player()
{
}


Player::~Player()
{
}

void Player::Init()
{
	_name = "Erik";
	_tag = "Player";
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(Vector2(300, 293));
	AddComponent<PhysicsBodyComponent>();
	GetComponent<PhysicsBodyComponent>()->Init(DYNAMIC);

	_graphic = AddComponent<GraphicComponent>();
	GetComponent<GraphicComponent>()->Init(true);
	GetComponent<GraphicComponent>()->SetImgName("number1");

}

void Player::Update()
{
	float speed = 5.f;

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_trans->SetPos(Vector2(_trans->GetPos() + Vector2::up * speed));
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_trans->SetPos(Vector2(_trans->GetPos() + Vector2::down * speed));
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_trans->SetPos(Vector2(_trans->GetPos() + Vector2::left * speed));
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_trans->SetPos(Vector2(_trans->GetPos() + Vector2::right * speed));
	}
	if (_trans->GetX() > WINSIZEX / 2 &&
		_trans->GetX() < 2000 - WINSIZEX / 2||
		_trans->GetY() > WINSIZEY / 2 &&
		_trans->GetY() < 1580 - WINSIZEY / 2 )
	{
		Vector2 A(_trans->GetY() - WINSIZEX / 2, _trans->GetY() - WINSIZEY / 2);
		CAMERA->SetPosition(A);
	}
	super::Update();
}

void Player::Release()
{
	super::Release();

}
