#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "EnemyCollision.h"

void Enemy::Init()
{
	//충돌

	_physics = AddComponent<PhysicsBodyComponent>();

	GRAPHICMANAGER->AddFrameImage("greenAttack", L"greenAttack.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("greenMove", L"greenMove.png", 3, 2);
	GRAPHICMANAGER->AddImage("cannon_bullet", L"cannon_bullet.png");

	_trans->SetPos(Vector2(
		WINSIZEX / 2, 
		WINSIZEY-100));
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameWidth(),
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameHeight()));

	_physics->Init(DYNAMIC, 5.f, 3.f, 0);
	_physics->GetBody()->SetFixedRotation(true);	//회전값 안받음
	_physics->GetBody()->SetGravityScale(0);		//중력 안받음

	_graphic->Init(true, true);
	_graphic->SetImgName("greenMove"); 	//출력되는 그림
	_graphic->SetFrameY(1);

	AddComponent<EnemyCollision>();
	_speed = 2.; //안쓸거같은데 일단 해둠
	_state = MOVE_LEFT;
	_isAttack = false;
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
	switch (_state)
	{
		case MOVE_LEFT:
			_graphic->SetImgName("greenMove");
			_graphic->SetFrameY(1);
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Left * _speed);
		
		break;
		case MOVE_RIGHT:
			_graphic->SetImgName("greenMove");
			_graphic->SetFrameY(0);
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Right * _speed);
				
		break;
		case ATTACK_LEFT:
			_graphic->SetImgName("greenAttack");
			_graphic->SetFrameY(1);
			_isAttack = true;
		break;
		case ATTACK_RIGHT:
			_graphic->SetImgName("greenAttack");
			_graphic->SetFrameY(1);
			_isAttack = true;
		break;
	}

	//trans 위치와 피직스 값 동기화
	_trans->SetPos(_physics->GetBodyPosition());
}

void Enemy::Shoot()
{
	if (_isAttack)
	{
		if (_state == ATTACK_LEFT)
		{
			_isAttack = false;
			//총쏘기 내용 여기
			_state = MOVE_LEFT; //한발 쏘고 다시 움직이라고..
		}
		if (_state == ATTACK_RIGHT)
		{
			_isAttack = false;
			//총쏘기 내용 여기
			_state = MOVE_RIGHT;//한발 쏘고 다시 움직이라고..
		}
	}
}
