#include "stdafx.h"
#include "Enemy.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "EnemyCollision.h"

void Enemy::Init()
{
	//�浹
	AddComponent<EnemyCollision>();

	_physics = AddComponent<PhysicsBodyComponent>();

	GRAPHICMANAGER->AddFrameImage("greenAttack", L"greenAttack.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("greenMove", L"greenMove.png", 3, 2);
	GRAPHICMANAGER->AddImage("cannon_bullet", L"cannon_bullet.png");

	_trans->SetPos(Vector2(
		WINSIZEX / 2, 
		WINSIZEY -100- GRAPHICMANAGER->FindImage("greenAttack")->GetFrameHeight()));
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameWidth(),
		GRAPHICMANAGER->FindImage("greenAttack")->GetFrameHeight()));

	_graphic->Init(true, true);
	//��µǴ� �׸�
	_graphic->SetImgName("greenMove"); 
	_graphic->SetFrameY(1);

	_physics->Init(DYNAMIC, 5.f, 3.f, 0);

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
		break;
		case ATTACK_RIGHT:
			_graphic->SetImgName("greenAttack");
			_graphic->SetFrameY(1);
		break;
	}

	//trans ��ġ�� ������ �� ����ȭ
	_trans->SetPos(_physics->GetBodyPosition());
}

void Enemy::Shoot()
{
	if (_isAttack)
	{
		//����
	}
}
