#include "stdafx.h"
#include "Character.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"

Character::Character()
{

}

Character::~Character()
{

}

void Character::Init()
{
	_hp = 3;
	_moveSpeedX = 2.f;
	_moveSpeedY = 1.f;

	_tag = "Player";
	//_physics->Init(DYNAMIC);

	_state =  AddComponent<StateComponent>();
	_physics = AddComponent<PhysicsBodyComponent>();

	_trans->SetScale(84, 100);
	_trans->SetPos(WINSIZEX / 2, 200);

	_physics->Init(DYNAMIC, 0.5f);

	_state->SetState(RIGHT_IDLE);
}

void Character::Update()
{
	super::Update();

	KeyControl();
}

void Character::Release()
{
	super::Release();
}

void Character::KeyControl()
{

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_state->SetState(LEFT_IDLE);
		_physics->ApplyForce(Vector2::b2Left * 10);
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_state->SetState(LEFT_MOVE);
		_physics->ApplyForce(Vector2::b2Left * 10);
		//Move(이미지이름);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state->SetState(LEFT_IDLE);
		_physics->ApplyForce(Vector2::b2Up * 100);
	}


	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_state->SetState(RIGHT_IDLE);
		_physics->ApplyForce(Vector2::b2Right * 10);
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_state->SetState(RIGHT_MOVE);
		_physics->ApplyForce(Vector2::b2Right * 10);
		//Move(이미지이름);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state->SetState(RIGHT_IDLE);
		_physics->ApplyForce(Vector2::b2Up * 100);
	}


	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_state->GetState() == LEFT_IDLE || _state->GetState() == LEFT_MOVE)
		{
			_state->SetState(RIGHT_MOVE);
			//_physics->ApplyForce(Vector2::b2Up * upPower);
			Ladder();
		}
		else if (_state->GetState() == RIGHT_IDLE || _state->GetState() == RIGHT_MOVE)
		{

			_state->SetState(RIGHT_MOVE);
			_physics->ApplyForce(Vector2::b2Up * upPower);
			Ladder();
		}

		//_physics->ApplyForce(Vector2::b2Up * upPower);
		//upPower -= 10;
		
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{

	}

	_trans->SetPos(_physics->GetBodyPosition());


}

void Character::Idle(string key)
{
	_graphic->SetImgName(key);
}

void Character::Death(string key)
{
	_graphic->SetImgName(key);
}

void Character::Floating(string key)
{
	_graphic->SetImgName(key);
}

void Character::Hit(string key)
{
	_graphic->SetImgName(key);
}

void Character::Ladder(string key)
{
	_graphic->SetImgName(key);
}

void Character::Move(string key)
{
	_graphic->SetImgName(key);
}

void Character::Ladder()
{
	_state->SetState(LADDER);
}