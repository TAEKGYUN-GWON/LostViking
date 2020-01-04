#include "stdafx.h"
#include "PMgr.h"
#include"GraphicComponent.h"
#include"TransformComponent.h"
PMgr::PMgr()
{
}


PMgr::~PMgr()
{
}

void PMgr::Init()
{
	GRAPHICMANAGER->AddFrameImage("Baleog Idle", L"img/player/Baleog/idle.png",2,2);
	GRAPHICMANAGER->AddFrameImage("Baleog Move", L"img/player/Baleog/move.png",8,2);
	GRAPHICMANAGER->AddFrameImage("Baleog Jump", L"img/player/Baleog/jump.png",2,2);
	GRAPHICMANAGER->AddFrameImage("Baleog Ladder", L"img/player/Baleog/ladder.png",6,1);
	GRAPHICMANAGER->AddFrameImage("Baleog Push", L"img/player/Baleog/pushWall.png",4,2);
	GRAPHICMANAGER->AddFrameImage("Baleog Epic1", L"img/player/Baleog/sword1.png",4,2);
	GRAPHICMANAGER->AddFrameImage("Baleog Epic2", L"img/player/Baleog/sword2.png",4,2);
	GRAPHICMANAGER->AddFrameImage("Baleog Epic3", L"img/player/Baleog/arrow.png",8,2);
	GRAPHICMANAGER->AddImage("Baleog Hit", L"img/player/Baleog/hit.png");
	p = new Player;
	p->Init(Vector2(1921.5f,1441),"Baleog");
	p->SetTurn();
	_bullet = new Bullet;
	GRAPHICMANAGER->AddImage("Arrow", L"img/Arrow.png");
	GRAPHICMANAGER->AddImage("Arrow2", L"img/Arrow2.png");
	_bullet->Init("Arrow", "Arrow", "Arrow");
}

void PMgr::Update()
{
	p->Update();

	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		_bullet->GetGraphic()->SetImgName("Arrow");
		_bullet->Fire(p->GetTrans()->pos+Vector2::left*60, PI, 8);
	}
	if (KEYMANAGER->isOnceKeyDown('U'))
	{
		_bullet->GetGraphic()->SetImgName("Arrow2");
		_bullet->Fire(p->GetTrans()->pos + Vector2::right * 60, PI2, 8);
	}
	_bullet->Update();
	if (!_bullet->GetIsActive())
		_bullet->GetComponent<PhysicsBodyComponent>()->SetBodyActive(false);

}

void PMgr::Render()
{
	p->Render();
	if (_bullet->GetIsActive())
		_bullet->Render();
}
