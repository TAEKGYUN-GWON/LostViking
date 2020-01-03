#include "stdafx.h"
#include "EnemyCollision.h"
#include "Object.h"
#include "enemy.h"
#include "Gate.h"
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

	//���� ������
	if ((collisionObj->GetName() == "Barrier" || collisionObj->GetName() == "eBarrier") && enemy->GetState() == MOVE_LEFT)
	{

		enemy->SetState(MOVE_RIGHT);
	}
	else if ((collisionObj->GetName() == "Barrier" || collisionObj->GetName() == "eBarrier" ) && enemy->GetState() == MOVE_RIGHT)
	{
		enemy->SetState(MOVE_LEFT);
	}

	else if (collisionObj->GetTag() == "Gate"&& enemy->GetState() == MOVE_LEFT || enemy->GetState() == ATTACK_LEFT)
	{
		Gate* gate = (Gate*)collisionObj;
		if (!gate->GetIsOn())
			enemy->SetState(MOVE_RIGHT);
	}
	else if (collisionObj->GetTag() == "Gate"&& enemy->GetState() == MOVE_RIGHT || enemy->GetState() == ATTACK_RIGHT)
	{
		Gate* gate = (Gate*)collisionObj;
		if (!gate->GetIsOn())
			enemy->SetState(MOVE_LEFT);
	}

	//ĳ���Ͷ� ������
	if (collisionObj->GetTag() == "Player" && enemy->GetState() == MOVE_LEFT)
	{
		enemy->SetState(ATTACK_LEFT);
	}
	else if (collisionObj->GetTag() == "Player" && enemy->GetState() == MOVE_RIGHT)
	{
		enemy->SetState(ATTACK_RIGHT);
	}
}


void EnemyCollision::CollisionEnd(void * obj)
{
}
