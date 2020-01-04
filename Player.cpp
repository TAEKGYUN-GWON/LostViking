#include "stdafx.h"
#include "Player.h"
#include"TransformComponent.h"
#include"GraphicComponent.h"
#include"PlayerScript.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::Init(Vector2 pos, string name)
{
	_tag = "Player1";
	_playerName = name;
	string key = name + " Idle";
	_graphic->Init(true, true);
	_graphic->SetImgName(key);
	_trans->pos = pos;
	_trans->SetScale(Vector2(_graphic->GetGraphic()->GetFrameWidth(),
							 _graphic->GetGraphic()->GetFrameHeight()));

	_state = AddComponent<State>();
	_state->state = IDLE;
	_state->direction = 0;
	_physics = AddComponent<PhysicsBodyComponent>();
	_physics->Init(DYNAMIC, 1,0.51);
	_physics->GetBody()->SetFixedRotation(true);
	AddComponent< PlayerScript>();
	_hp = 3;
	_isTurn = _laddering = 0;
	_speed = 4.5f;
}

void Player::Release()
{
}

void Player::Update()
{
	super::Update();
	if (PlayerDead()) return;
	if (!_isTurn)return;
	KeyCon();
	ImgCon();
	CAMERA->SetPosition(_trans->pos);
}

void Player::KeyCon()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		b2Vec2 velocity = _physics->GetBody()->GetLinearVelocity();
		float force = (velocity.x < _speed) ? (_speed) : (0.f);
		_physics->ApplyForce(Vector2::b2Left * force);
		_state->direction = 0;
		if (_state->state != JUMP) _state->state = MOVE;
		
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		if (_state->state != JUMP)
			_state->state = IDLE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		b2Vec2 velocity = _physics->GetBody()->GetLinearVelocity();
		float force = (velocity.x < _speed) ? (_speed) : (0.f);
		_physics->ApplyForce(Vector2::b2Right * force);
		_state->direction = 1;
		if(_state->state !=JUMP) _state->state = MOVE;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		if (_state->state != JUMP)
			_state->state = IDLE;
	}

	if (_laddering)
	{
		int a = 0;
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_trans->pos.x = _LadderPos.x;
			_trans->SetPos(_trans->GetPos() + Vector2::up*_speed);
			_physics->SetBodyPosition();
			_state->state = ISLADDER;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_trans->pos.x = _LadderPos.x;
			if(_trans->pos.y + _trans->scale.y/2 < (_LadderPos.y + _LadderScale.y/2)-5)
			_trans->SetPos(_trans->GetPos() + Vector2::down*_speed);
				_physics->SetBodyPosition();
			_state->state = ISLADDER;
		}
	}
	if (_state->state != JUMP)
	{
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			Epic1();
			_state->state = SPECIAL1;
		}
		if (KEYMANAGER->isOnceKeyUp('D'))
		{
			if (_state->state != JUMP)
				_state->state = IDLE;
		}

		if (KEYMANAGER->isStayKeyDown('F'))
		{
			Epic2();
			_state->state = SPECIAL2;
		}

		if (KEYMANAGER->isOnceKeyUp('F'))
		{
			if (_state->state != JUMP)
				_state->state = IDLE;
		}
	}
	if (_state->state != ISLADDER)
	{
		if (_physics->GetBody()->GetGravityScale() == 0)_physics->GetBody()->SetGravityScale(1);
		_trans->SetPos(_physics->GetBodyPosition());
	}
	else
	{
		_physics->GetBody()->SetGravityScale(0);
		_physics->SetBodyPosition();
	}

	cout << _laddering << endl;
}

void Player::ImgCon()
{
	if (_state->state == IDLE) _graphic->SetImgName(_playerName + " Idle");
	else if (_state->state == MOVE) _graphic->SetImgName(_playerName + " Move");
	else if (_state->state == JUMP) _graphic->SetImgName(_playerName + " Jump");
	else if (_state->state == ISLADDER) _graphic->SetImgName(_playerName + " Ladder");
	else if (_state->state == SPECIAL1)	_graphic->SetImgName(_playerName + " Epic1");
	else if (_state->state == SPECIAL2)
	{
		if (_playerName != "Baleog")
			_graphic->SetImgName(_playerName + " Epic2");
		else
			_graphic->SetImgName(_playerName + " Epic3");
	}
	if (_state->direction == 0)_graphic->SetFrameY(1);
	else _graphic->SetFrameY(0);
}

bool Player::PlayerDead()
{
	if (_hp <= 0)_state->state = DEATH;

	if (_state->state == DEATH) return true;
	else return false;
}
