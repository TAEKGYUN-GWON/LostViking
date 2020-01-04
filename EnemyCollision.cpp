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
	//충돌 당하는 애
	Object* collisionObj = (Object*)obj;

	//초록 에너미
	Enemy* enemy = (Enemy*)_object;

	//벽에 닿으면
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

	//캐릭터랑 닿으면
	if (collisionObj->GetTag() == "Player" && enemy->GetState() == MOVE_LEFT)
	{
		enemy->SetState(ATTACK_LEFT);
		enemy->SetAttack(true);
	}
	else if (collisionObj->GetTag() == "Player" && enemy->GetState() == MOVE_RIGHT)
	{
		enemy->SetState(ATTACK_RIGHT);
		enemy->SetAttack(true);
	}

	

}


void EnemyCollision::CollisionEnd(void * obj)
{
}
