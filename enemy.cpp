#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "EnemyCollision.h"

void Enemy::Init()
{
	//�浹

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
	_physics->GetBody()->SetFixedRotation(true);	//ȸ���� �ȹ���
	_physics->GetBody()->SetGravityScale(0);		//�߷� �ȹ���

	_graphic->Init(true, true);
	_graphic->SetImgName("greenMove"); 	//��µǴ� �׸�
	_graphic->SetFrameY(1);

	AddComponent<EnemyCollision>();
	_speed = 2.; //�Ⱦ��Ű����� �ϴ� �ص�
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

	//trans ��ġ�� ������ �� ����ȭ
	_trans->SetPos(_physics->GetBodyPosition());
}

void Enemy::Shoot()
{
	if (_isAttack)
	{
		if (_state == ATTACK_LEFT)
		{
			_isAttack = false;
			//�ѽ�� ���� ����
			_state = MOVE_LEFT; //�ѹ� ��� �ٽ� �����̶��..
		}
		if (_state == ATTACK_RIGHT)
		{
			_isAttack = false;
			//�ѽ�� ���� ����
			_state = MOVE_RIGHT;//�ѹ� ��� �ٽ� �����̶��..
		}
	}
}
