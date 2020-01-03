#pragma once
#include "Tomato.h"
#include "Meat.h"
#include "Bomb.h"
#include "Plasma.h"
#include "RedgunTower.h"
#include "Computer.h"
#include "Button.h"
#include "D2DEffect.h"
#include "Bullet.h"
#include <vector>
#include "ObjectPool.h"

class ObjectManager 
{
private:

	vector<Item*>				_vItem;
	vector<Item*>::iterator		_viItem;

	vector<Object*>				_vObject;
	vector<Object*>::iterator	_viObject;

	ObjectPool*					_objPool;

	vector<D2DEffect*>			_vEffect;

public:

	void Init();
	void Release();
	void Update();
	void Render();
	void PlasmaOff(string btn, string pla);
	void Fire();
};

