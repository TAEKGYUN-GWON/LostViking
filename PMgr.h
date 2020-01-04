#pragma once
#include"Player.h"
#include"Bullet.h"
class PMgr
{
private:
	Player* p;
	Bullet*_bullet;
public:
	PMgr();
	~PMgr();
	void Init();
	void Update();
	void Render();
};

