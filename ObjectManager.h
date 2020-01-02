#pragma once
#include "Tomato.h"
#include "Meat.h"
#include "Bomb.h"
#include "Plasma.h"
#include "RedgunTower.h"
#include "Computer.h"
#include "Button.h"
#include <vector>
#include "ObjectPool.h"

class ObjectManager 
{
private:

	vector<Item*>			_vItem;
	vector<Item*>::iterator	_viItem;

	vector<Object*>				_vObject;
	vector<Object*>::iterator	_viObject;

	bool _isTest;

	ObjectPool*					_objPool;

public:

	void Init();
	void Release();
	void Update();
	void Render();
};

