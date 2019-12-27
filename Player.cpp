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
		Vector2 a = Vector2::up; 
		_trans->SetPos(Vector2(_trans->GetPos()+a*speed));
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		Vector2 a = Vector2::down;
		_trans->SetPos(Vector2(_trans->GetPos() + a * speed));
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		Vector2 a = Vector2::left;
		_trans->SetPos(Vector2(_trans->GetPos() + a * speed));
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		Vector2 a = Vector2::right;
		_trans->SetPos(Vector2(_trans->GetPos() + a * speed));
	}
	super::Update();
}

void Player::Release()
{
	super::Release();

}
