#include "stdafx.h"
#include "ObjectManager.h"

void ObjectManager::Init()
{
	Item* item;
	item = new Tomato;
	//item->Init(Vector2(100, 100));
	item->Init(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	_vItem.push_back(item);
	
	Bullet* bullet = new Bullet;
	bullet->Init("enemy_bullet", "Bullet", "EnemyBullet");

	_objPool = new ObjectPool;
	_objPool->Init<Bullet>(30, *bullet);
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

	for (Object* a : _objPool->GetActivePool()) a->Update();

	TomatoFire();
}

void ObjectManager::Render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Render();
	}

	for (Object* a : _objPool->GetActivePool())
		a->Render();
}

void ObjectManager::TomatoFire() //������ƮǮ�� �ִ� �Ѿ��� �������� fire (bullet.fire�� ����
{//pos, angle, speed
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		((Bullet*)_objPool->GetPoolObject())->Fire(Vector2(1772, 650
			), PI2, 200.0f);
		_objPool->InssertActiveObject();
	}

	for (int i = 0; i < _objPool->GetActivePoolSize(); i++)
	{
		if (!_objPool->GetActivePool()[i]->GetIsActive())
			_objPool->InssertPool(i);
	}
}
