#include "stdafx.h"
#include "Character.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "ErikScript.h"

Character::Character()
{

}

Character::~Character()
{

}

void Character::Init()
{
	_hp = 3;
	_moveSpeedX = 10.f;
	_moveSpeedY = 1.f;

	_tag = "Player";
	//_physics->Init(DYNAMIC);

	_state =  AddComponent<StateComponent>();
	_physics = AddComponent<PhysicsBodyComponent>();
	AddComponent<ErikScript>();

	_trans->SetScale(84, 100);
	_trans->SetPos(WINSIZEX / 2 - 200, 200);

	_physics->Init(DYNAMIC,0.5f);

	_state->SetState(RIGHT_IDLE);
	/*GRAPHICMANAGER->AddFrameImage();
	_graphic->Init(true, true);
	_graphic->SetImgName();*/

	_physics->GetBody()->SetFixedRotation(true);
	_isLadder = false;	//사다리에 붙었는지
	_isDead = false;	//아뇨, 안죽었어용
}

void Character::Update()
{
	super::Update();

	KeyControl();

	CAMERA->SetPosition(_trans->GetPos());
	cout << _state->GetState() << endl;
}

void Character::Release()
{
	super::Release();
}

void Character::KeyControl()
{
	if (_isLadder)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
			_physics->GetBody()->SetGravityScale(0);
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Up * _moveSpeedY);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{


		_state->SetState(LEFT_IDLE);
		_physics->ApplyForce(Vector2::b2Left * _moveSpeedX);

		_physics->GetBody()->SetGravityScale(1);
		//_physics->GetBody()->GetFixtureList()->SetDensity(100);
		//_physics->ApplyForce(Vector2::b2Right * _moveSpeedX);
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_state->SetState(LEFT_MOVE);
		_physics->ApplyForce(Vector2::b2Left * _moveSpeedX);
		//Move(이미지이름);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state->SetState(LEFT_IDLE);
		//_physics->ApplyForce(Vector2::b2Up * 100);
	}


	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_state->SetState(RIGHT_IDLE);
		_physics->ApplyForce(Vector2::b2Right * _moveSpeedX);
		_physics->GetBody()->SetGravityScale(1);
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_state->SetState(RIGHT_MOVE);
		_physics->ApplyForce(Vector2::b2Right * _moveSpeedX);
		//Move(이미지이름);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state->SetState(RIGHT_IDLE);

		//_graphic->SetImgName();
	}


	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{

	}

	if (KEYMANAGER->isOnceKeyDown('E'))
	{

	}


	_trans->SetPos(_physics->GetBodyPosition());


}

void Character::ChangeImage(string key)
{
	_graphic->SetImgName(key);
}

