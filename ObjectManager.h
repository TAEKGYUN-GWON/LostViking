#pragma once
#include "Tomato.h"
#include "Bullet.h"
#include <vector>
#include "ObjectPool.h"

class ObjectManager 
{
private:
	vector<Item*>				_vItem;
	vector<Item*>::iterator		_viItem;

	vector<Bullet*>				_vBullet;
	vector<Bullet*>::iterator	_viBullet;

	int							_nowCharactor;
	vector<Object*>				_player;

	ObjectPool*					_objPool;

public:
	void Init();
	void Release();
	void Update();
	void Render();

	void TomatoFire();
};

