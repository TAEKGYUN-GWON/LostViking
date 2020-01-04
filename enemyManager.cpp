#include "stdafx.h"
#include "EnemyManager.h"
#include"TransformComponent.h"
#include"GraphicComponent.h"
#include "Bullet.h"

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
		enemy->Init(Vector2(1772, 600), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(1000, 880), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(600, 1534), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(550, 2000), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy;
		enemy->Init(Vector2(480, 2233), "greenAttack", 2.f, MOVE_LEFT, false, 0.f, -1);

		_vEnemy.push_back(enemy);
	}

	GRAPHICMANAGER->AddImage("BulletImage", L"cannon_bullet.png");

	Bullet *bullet = new Bullet;
	bullet->Init("BulletImage", "Bullet","enemyBullet");
	
	_objectPool = new ObjectPool;
	_objectPool->Init<Bullet>(50, *bullet);

}

void EnemyManager::Release()
{
}

void EnemyManager::Update()
{
	for (Enemy *enemy : _vEnemy)
		enemy->Update();

	//활성화된 총알을 업데이트 해주는 과정
	for (Object *B : _objectPool->GetActivePool())
		B->Update();

	
	EnemyFire();
}

void EnemyManager::Render()
{
	for (Enemy *enemy : _vEnemy)
		enemy->Render();

	//활성화된 총알을 그리는 과정
	for (Object *B : _objectPool->GetActivePool())
		B->Render();
}

void EnemyManager::EnemyFire()
{
	for (Enemy *enemy : _vEnemy)
	{
		if (enemy->GetState() == ATTACK_LEFT)
		{
			if (enemy->IsFire())
			{

				((Bullet*)_objectPool->GetPoolObject())->Fire(
					(Vector2(enemy->GetTrans()->pos.x + 10, enemy->GetTrans()->pos.y)),
					PI, 100);
				
				//오브젝트풀에서 총알을 꺼내오는 것
				_objectPool->InssertActiveObject();
							
			}
		}
		if (enemy->GetState() == ATTACK_RIGHT)
		{
			if (enemy->IsFire())
			{

				((Bullet*)_objectPool->GetPoolObject())->Fire(
					(Vector2(enemy->GetTrans()->pos.x + 10, enemy->GetTrans()->pos.y)),
					0, 100);

				_objectPool->InssertActiveObject();
			
			}
		}
	}	

	//끝난 총알을 다시 오브젝트풀에 넣는 것
	for (int i = 0; i < _objectPool->GetActivePoolSize(); i++)
	{
		if (!_objectPool->GetActivePool()[i]->GetIsActive())
		{
			_objectPool->GetActivePool()[i]->GetComponent<PhysicsBodyComponent>()->GetBody()->SetActive(false);
			_objectPool->InssertPool(i);
		}
	}



}
