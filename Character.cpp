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

	_tag = "Viking";
	//_physics->Init(DYNAMIC);

	_state =  AddComponent<StateComponent>();
	_physics = AddComponent<PhysicsBodyComponent>();
	AddComponent<ErikScript>();

	_trans->SetScale(84, 100);
	_trans->SetPos(WINSIZEX / 2, 200);

	_physics->Init(DYNAMIC,0.9f);

	_state->SetState(RIGHT_IDLE);

	_isLadder = false;
}

void Character::Update()
{
	super::Update();

	KeyControl();

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
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			/*if (_state->GetState() == LEFT_IDLE || _state->GetState() == LEFT_MOVE)
			{
				_state->SetState(RIGHT_MOVE);
				//_physics->ApplyForce(Vector2::b2Up * upPower);
				Ladder();
			}
			else if (_state->GetState() == RIGHT_IDLE || _state->GetState() == RIGHT_MOVE)
			{

				_state->SetState(RIGHT_MOVE);
				Ladder();
			}*/

			if (_isLadder)
				_trans->SetPos(_trans->pos + Vector2::up * 3);
		}
		/*if (KEYMANAGER->isStayKeyDown(VK_UP))
			_trans->SetPos(_trans->pos + Vector2::up * 3);*/
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_state->SetState(LEFT_IDLE);
		_physics->ApplyForce(Vector2::b2Left * _moveSpeedX);

		b2Fixture* f;
		for (f = _physics->GetBody()->GetFixtureList(); f; f = f->GetNext())
		{
			f->SetFriction(20.f);
		}

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
		//Idle(이미지이름);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_state->SetState(RIGHT_MOVE);
		//_physics->GetBody()->SetLinearVelocity(Vector2::b2Right * 3);
		_physics->ApplyForce(Vector2::b2Right * _moveSpeedX);
		//Move(이미지이름);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state->SetState(RIGHT_IDLE);

	}


	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{

	}

	/*if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		_isLadder = !_isLadder;// = false;*/


	if (!_isLadder)
		_trans->SetPos(_physics->GetBodyPosition());
	//else
		//_physics->SetBodyPosition();


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
	//_state->SetState(LADDER);
}