#include "stdafx.h"
#include "Bullet.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"
#include "GraphicComponent.h"
#include "bulletScript.h"

void Bullet::Init(string imgKey, string tag, string name)
{
	_tag = tag;
	_name = name;

	_graphic->Init();
	_graphic->SetImgName(imgKey);
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(), _graphic->GetGraphic()->GetFrameHeight());

	_physics = AddComponent<PhysicsBodyComponent>();
	_physics->Init(BodyType::DYNAMIC, 1.0f, 1.0f, 0.0f);
	AddComponent<bulletScript>();
	_physics->GetBody()->SetFixedRotation(true);

	_physics->GetBody()->SetGravityScale(0);

	_isActive = false;
}

void Bullet::Update()
{
	Move();
	_trans->pos = _physics->GetBodyPosition();

	super::Update();
}

void Bullet::Fire(Vector2 pos, float angle, float speed)
{
	_speed = speed;
	_trans->pos = Vector2(0,-20);
	_physics->SetBodyPosition();
	_trans->SetRotateToRadian(angle);
	_isActive = true;
}

void Bullet::Move()
{
	//_trans->pos.x += cosf(_trans->GetRotateRadian()) * _speed;
	//_trans->pos.y -= sinf(_trans->GetRotateRadian()) * _speed;
	//_physics->GetBody()->SetLinearVelocity(Vector2::b2Right * 30);
	//_physics->ApplyForce(_physics->GetBodyPosition() * PHYSICSMANAGER->GetWorld()->GetGravity());

	//_physics->GetBody()->SetGravityScale(0);
	_physics->ApplyForce(Vector2::b2Right * _speed * TIMEMANAGER->getElapsedTime());
}
