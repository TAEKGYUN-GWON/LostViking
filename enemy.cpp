#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "EnemyCollision.h"

void Enemy::Init()
{

	_physics = AddComponent<PhysicsBodyComponent>();

	GRAPHICMANAGER->AddFrameImage("greenAttack", L"greenAttack.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("greenMove", L"greenMove.png", 3, 2);
	GRAPHICMANAGER->AddImage("cannon_bullet", L"cannon_bullet.png");

	_trans->SetPos(Vector2(WINSIZEX / 2, WINSIZEY -100- GRAPHICMANAGER->FindImage("greenAttack")->GetFrameHeight()));
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameWidth(),
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameHeight()));

	_graphic->Init(true, true);
	//_graphic->SetImgName("greenAttack");
	_graphic->SetImgName("greenMove");

	_physics->Init(DYNAMIC, 5.f, 3.f, 0);

	_speed = 3; //안쓸거같은데 일단 해둠
	_state = MOVE_LEFT;
	AddComponent<EnemyCollision>();
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	Move();
	Shoot();

	super::Update();
}

void Enemy::Render()
{
	//GRAPHICMANAGER->DrawFrameImage("greenAttack", Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, 0);

	super::Render();
}

void Enemy::Move()
{
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	//{
	//	_physics->ApplyForce(Vector2::b2Left * 5.f);
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	//{
	//	_physics->ApplyForce(Vector2::b2Right * 5.f);
	//}

	switch (_state)
	{
		case MOVE_LEFT:
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Left * 5.f);

		break;
		case MOVE_RIGHT:
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Right * 5.f);

		break;
		//case ATTACK_LEFT:


		//break;
		//case ATTACK_RIGHT:


		//break;
	}



	//trans 위치와 피직스 값 동기화
	_trans->SetPos(_physics->GetBodyPosition());
}

void Enemy::Shoot()
{
}
