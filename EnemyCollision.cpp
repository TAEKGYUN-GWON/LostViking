#include "stdafx.h"
#include "EnemyCollision.h"
#include "Object.h"
#include "enemy.h"

EnemyCollision::EnemyCollision()
{
}


EnemyCollision::~EnemyCollision()
{
}

void EnemyCollision::CollisionBegin(void * obj)
{
	//충돌 당하는 애
	Object* collisionObj = (Object*)obj;

	//초록 에너미
	Enemy* enemy = (Enemy*)_object;

	//왼쪽 벽에 닿으면
	if (collisionObj->GetName() == "LEFT_WALL")
	{
		enemy->setState(MOVE_RIGHT);
	}
	//오른쪽 벽에 닿으면
	if (collisionObj->GetName() == "RIGHT_WALL")
	{
		enemy->setState(MOVE_LEFT);
	}
}

void EnemyCollision::CollisionEnd(void * obj)
{
}
