#pragma once
#include "enemy.h"
#include "ObjectPool.h"

class EnemyManager
{
private:
	vector<Enemy*> _vEnemy;

	ObjectPool *_objectPool;

public:
	EnemyManager();
	~EnemyManager();

	void Init();
	void Release();
	void Update();
	void Render();

	void EnemyFire();
	
};

