#include "stdafx.h"
#include "ObjectManager.h"

void ObjectManager::Init()
{
	Item* item;
	item = new Tomato;
	//item->Init(Vector2(100, 100));
	item->Init(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	_vItem.push_back(item);
	
	
}

void ObjectManager::Release()
{

}

void ObjectManager::Update()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Update();
	}
	
	if(_bullet) if(_bullet->GetIsActive()) _bullet->Update();
	
	TomatoFire();
}

void ObjectManager::Render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Render();
	}

	if (_bullet) _bullet->Render();
}

void ObjectManager::TomatoFire()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_bullet = new Bullet;
		_bullet->Init("enemy_bullet", "Bullet", "enemy");
		_bullet->Fire(_vItem[0]->GetTrans()->pos, PI / 2, 1.0f);
	}
}
