#pragma once
#include "Tomato.h"
#include "Bullet.h"
#include <vector>

class ObjectManager 
{
private:
	vector<Item*>				_vItem;
	vector<Item*>::iterator		_viItem;

	//vector<Bullet*>				_vBullet;
	//vector<Bullet*>::iterator	_viBullet;
	Bullet*						_bullet;

public:
	void Init();
	void Release();
	void Update();
	void Render();

	void TomatoFire();
};

