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
	//�浹 ���ϴ� ��
	Object* collisionObj = (Object*)obj;

	//�ʷ� ���ʹ�
	Enemy* enemy = (Enemy*)_object;

	//���� ���� ������
	if (collisionObj->GetName() == "LEFT_WALL")
	{
		enemy->setState(MOVE_RIGHT);
	}
	//������ ���� ������
	if (collisionObj->GetName() == "RIGHT_WALL")
	{
		enemy->setState(MOVE_LEFT);
	}
}

void EnemyCollision::CollisionEnd(void * obj)
{
}
