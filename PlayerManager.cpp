#include "stdafx.h"
#include "PlayerManager.h"
#include"TransformComponent.h"
#include"GraphicComponent.h"
PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

void PlayerManager::Init()
{
	/*Character* c = new Character;
	c->Init(WINSIZEX / 2 - 200, 200);*/

	//_erik = new Erik;
	//_erik->Init(WINSIZEX/2-200, WINSIZEY/2);
	_olaf = new Olaf;
	_olaf->Init(WINSIZEX / 2 - 350, WINSIZEY / 2);
	_olaf->SetTurn(true);
	//_vPlayer.push_back(_erik);
	_vPlayer.push_back(_olaf);
	_bullet = new Bullet;
	GRAPHICMANAGER->AddImage("Arrow", L"img/Arrow.png");
	GRAPHICMANAGER->AddImage("Arrow2", L"img/Arrow2.png");
	_bullet->Init("Arrow", "Arrow", "Arrow");

}

void PlayerManager::Release()
{

}

void PlayerManager::Update()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		
		_vPlayer[i]->Update();

	}
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		_bullet->GetGraphic()->SetImgName("Arrow");
		_bullet->Fire(_olaf->GetTrans()->pos, PI, 8);
	}
	if (KEYMANAGER->isOnceKeyDown('U'))
	{
		_bullet->GetGraphic()->SetImgName("Arrow2");
		_bullet->Fire(_olaf->GetTrans()->pos, PI2, 8);
	}
	_bullet->Update();
	if (!_bullet->GetIsActive())
		_bullet->GetComponent<PhysicsBodyComponent>()->SetBodyActive(false);
}

void PlayerManager::Render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->Render();
	}
	if (_bullet->GetIsActive())
		_bullet->Render();
}

