#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"

void Enemy::Init()
{
	GRAPHICMANAGER->AddFrameImage("greenAttack", L"greenAttack.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("greenMove", L"greenMove.png", 3, 2);
	GRAPHICMANAGER->AddImage("cannon_bullet", L"cannon_bullet.png");

	_trans->SetPos(Vector2(WINSIZEX / 2, WINSIZEY/2));
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameWidth(),
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameHeight()));

	_graphic->Init();
	//_graphic->SetImgName("greenAttack");
	_graphic->SetImgName("greenMove");

	
	
}

void Enemy::Release()
{
}

void Enemy::Update()
{

	super::Update();
}

void Enemy::Render()
{
	//GRAPHICMANAGER->DrawFrameImage("greenAttack", Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, 0);

	super::Render();
}

void Enemy::Move()
{
}

void Enemy::Shoot()
{
}
