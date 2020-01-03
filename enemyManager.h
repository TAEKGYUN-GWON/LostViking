#pragma once
#include "enemy.h"

class EnemyManager
{
private:
	vector<Enemy*> _vEnemy;


public:
	EnemyManager();
	~EnemyManager();

	void Init();
	void Release();
	void Update();
	void Render();
	
};

