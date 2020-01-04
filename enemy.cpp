#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "EnemyCollision.h"

void Enemy::Init(Vector2 pos, string image, float speed, ENEMY_STATE state, bool isattack, float timer, int direction)
{
	//�浹

	_physics = AddComponent<PhysicsBodyComponent>();
	_tag = "Enemy";
	_name = "Enemy";
	_speed = speed; 
	_state = state;
	_isAttack = isattack;
	_timer = timer;
	_direction = direction; //������ -1, �������� 1
	_trans->pos = pos;

	_graphic->Init(true, true);
	_graphic->SetImgName(image); 	//��µǴ� �׸�
	_graphic->SetFrameY(1);

	_trans->SetScale(Vector2(
		_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight()));

	_physics->Init(DYNAMIC, 5.f, 3.f, 0,false,true);
	_physics->GetBody()->SetFixedRotation(true);	//ȸ���� �ȹ���
	_physics->GetBody()->SetGravityScale(0);		//�߷� �ȹ���

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

	//trans ��ġ�� ������ �� ����ȭ
	_trans->SetPos(_physics->GetBodyPosition());
}

void Enemy::Attack()
{
	if (_isAttack)
	{
		if (_state == ATTACK_LEFT)
		{
		
			_isAttack = false;
			//�ѽ�� ���� ����
			_timer += TIMEMANAGER->getElapsedTime();
			if (_timer >= 1.5f)
			{
				_state = MOVE_LEFT; //�ѹ� ��� �ٽ� �����̶��..
				_timer = 0.f;
			}
		}
		if (_state == ATTACK_RIGHT)
		{
			_isAttack = false;
			//�ѽ�� ���� ����
			_timer += TIMEMANAGER->getElapsedTime();
			if (_timer >= 1.5f)
			{
				_state = MOVE_RIGHT;//�ѹ� ��� �ٽ� �����̶��..
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
