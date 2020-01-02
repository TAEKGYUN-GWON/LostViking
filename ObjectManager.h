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



	ObjectPool*					_objPool;

public:
	void Init();
	void Release();
	void Update();
	void Render();

	void TomatoFire();
};

