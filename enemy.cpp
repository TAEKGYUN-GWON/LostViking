#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "EnemyCollision.h"

void Enemy::Init(Vector2 pos, string image, float speed, ENEMY_STATE state, bool isattack, float timer, int direction)
{
	//충돌

	_physics = AddComponent<PhysicsBodyComponent>();

	_speed = speed; 
	_state = state;
	_isAttack = isattack;
	_timer = timer;
	_direction = direction; //왼쪽이 -1, 오른쪽이 1
	_trans->pos = pos;

	_graphic->Init(true, true);
	_graphic->SetImgName(image); 	//출력되는 그림
	_graphic->SetFrameY(1);

	_trans->SetScale(Vector2(
		_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight()));

	_physics->Init(DYNAMIC, 5.f, 3.f, 0,false,true);
	_physics->GetBody()->SetFixedRotation(true);	//회전값 안받음
	_physics->GetBody()->SetGravityScale(0);		//중력 안받음

	_timer = _fireCount = 0;
	_direction = 0;

	AddComponent<EnemyCollision>();
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	Move();
	Attack();

	super::Update();
}

void Enemy::Render()
{
	
	super::Render();
}

void Enemy::Move()
{
	switch (_state)
	{
		case MOVE_LEFT:
			_direction = -1;
			_graphic->SetImgName("greenMove");
			_graphic->SetFrameY(1);
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Left * _speed);
		
		break;
		case MOVE_RIGHT:
			_direction = 1;
			_graphic->SetImgName("greenMove");
			_graphic->SetFrameY(0);
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Right * _speed);
				
		break;
		case ATTACK_LEFT:
			_direction = -1;
			_graphic->SetImgName("greenAttack");
			_graphic->SetFrameY(1);
			_isAttack = true;
		break;
		case ATTACK_RIGHT:
			_direction = 1;
			_graphic->SetImgName("greenAttack");
			_graphic->SetFrameY(0);
			_isAttack = true;
		break;
	}

	//trans 위치와 피직스 값 동기화
	_trans->SetPos(_physics->GetBodyPosition());
}

void Enemy::Attack()
{
	if (_isAttack)
	{
		if (_state == ATTACK_LEFT)
		{
		
			_isAttack = false;
			//총쏘기 내용 여기
			_timer += TIMEMANAGER->getElapsedTime();
			if (_timer >= 1.5f)
			{
				_state = MOVE_LEFT; //한발 쏘고 다시 움직이라고..
				_timer = 0.f;
			}
		}
		if (_state == ATTACK_RIGHT)
		{
			_isAttack = false;
			//총쏘기 내용 여기
			_timer += TIMEMANAGER->getElapsedTime();
			if (_timer >= 1.5f)
			{
				_state = MOVE_RIGHT;//한발 쏘고 다시 움직이라고..
				_timer = 0.f;
			}
		}
	}
}

bool Enemy::IsFire()
{
	_fireCount += TIMEMANAGER->getElapsedTime();
	if (_fireCount >= 1.5f)
	{
		_fireCount = 0;
		return true;
	}
	
	return false;
}
