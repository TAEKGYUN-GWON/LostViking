#include "stdafx.h"
#include "ObjectManager.h"

void ObjectManager::Init()
{
	Item* item;
	item = new Tomato;
	item->Init(Vector2(WINSIZEX / 2 - 100, WINSIZEY / 2));
	//_vItem.push_back(item);
	_player.push_back(item);

	item = new Tomato;
	item->Init(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	_player.push_back(item);

	item = new Tomato;
	item->Init(Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2));
	_player.push_back(item);

	_nowCharactor = 0;
}

void ObjectManager::Release()
{

}

void ObjectManager::Update()
{
	//for (int i = 0; i < _vItem.size(); i++)
	for (int i = 0; i < _player.size(); i++)
	{
		//_vItem[i]->Update();
		_player[i]->Update();
	}
	
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if ((*_viBullet)->GetIsActive()) (*_viBullet)->Update();
	}
	

	float speed = 90.0f;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _player[_nowCharactor]->GetTrans()->pos.x -= speed * TIMEMANAGER->getElapsedTime();
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _player[_nowCharactor]->GetTrans()->pos.x += speed * TIMEMANAGER->getElapsedTime();
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _player[_nowCharactor]->GetTrans()->pos.y -= speed * TIMEMANAGER->getElapsedTime();
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _player[_nowCharactor]->GetTrans()->pos.y += speed * TIMEMANAGER->getElapsedTime();


	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
	}

	TomatoFire();
}

void ObjectManager::Render()
{
	//for (int i = 0; i < _vItem.size(); i++)
	for (int i = 0; i < _player.size(); i++)
	{
		//_vItem[i]->Render();
		_player[i]->Render();
	}

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		(*_viBullet)->Render();
	}
}

void ObjectManager::TomatoFire()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		Bullet* bullet = new Bullet;
		bullet->Init("enemy_bullet", "Bullet", "enemy");
		bullet->Fire(_player[_nowCharactor]->GetTrans()->pos, PI2, 200.0f);

		_vBullet.push_back(bullet);
	}
}
