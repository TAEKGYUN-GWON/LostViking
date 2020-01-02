#include "stdafx.h"
#include "EnemyManager.h"
#include"TransformComponent.h"
#include"GraphicComponent.h"

EnemyManager::EnemyManager()
{
}
EnemyManager::~EnemyManager()
{
}

void EnemyManager::Init()
{
	GRAPHICMANAGER->AddFrameImage("greenAttack", L"greenAttack.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("greenMove", L"greenMove.png", 3, 2);
	GRAPHICMANAGER->AddImage("cannon_bullet", L"cannon_bullet.png");

	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(1772, 650), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(1000, 930), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(600, 1584), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(550, 2050), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(480, 2283), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
}

void EnemyManager::Release()
{
}

void EnemyManager::Update()
{
	for (Enemy *enemy : _vEnemy)
		enemy->Update();
}

void EnemyManager::Render()
{
	for (Enemy *enemy : _vEnemy)
		enemy->Render();
}
