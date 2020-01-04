#include "stdafx.h"
#include "Character.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "ErikScript.h"
#include "Inventory.h"
Character::Character()
{

}

Character::~Character()
{

}

void Character::Init(float spawnX, float spawnY)
{
	_hp = 3;
	_moveSpeedX = 4.f;
	_moveSpeedY = 2.f;

	_tag = "Player";
	//_physics->Init(DYNAMIC);

	_state =  AddComponent<StateComponent>();
	_physics = AddComponent<PhysicsBodyComponent>();
	AddComponent<ErikScript>();
	_inventory = AddComponent<Inventory>();
	_graphic->Init(true, true);

	_trans->SetScale(80, 100);
	//_trans->SetPos(WINSIZEX / 2 - 200, 200);
	_trans->SetPos(spawnX, spawnY);

	_physics->Init(DYNAMIC,.5f,.5f);

	//_lastPos = _physics->GetBodyPosition();

	_state->SetState(RIGHT_IDLE);
	/*GRAPHICMANAGER->AddFrameImage("");
	_graphic->Init(true, true);
	_graphic->SetImgName();*/
	_physics->GetBody()->SetFixedRotation(true);
	_isLadder = _isLaddering = false;				//사다리 안타고있어요
	_isDead = false;								//아뇨, 안죽었어용
	_isActive = false;								//상호작용 안할꺼에용
	_isGround = false;								//땅을 밟고 있습니까?
}

void Character::Update()
{
	super::Update();

	if(_isTurn)	KeyControl();

	if (!_isLaddering && !_isGround)
	{
		_isFloating = true;
		CheckLR();
		cout << _state->GetState() << endl;
	}
	else if (_isFloating)
	{
		if (_isGround)
		{
			_isFloating = false;

			if (_state->GetState() == LEFT_FLOATING)
				_state->SetState(LEFT_IDLE);
			else if (_state->GetState() == RIGHT_FLOATING)
				_state->SetState(RIGHT_IDLE);

			cout << _state->GetState() << endl;
		}
	}

	if (_isTurn) CAMERA->SetPosition(_trans->GetPos());
}

void Character::Release()
{
	super::Release();
}

void Character::KeyControl()
{
	if (_isLaddering)
	{
		//왼쪽
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x - _moveSpeedX, _trans->GetPos().y));
			_isLaddering = false;
			SetGravity(1);
			_state->SetState(LEFT_IDLE);
		}

		//오른쪽
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x + _moveSpeedX, _trans->GetPos().y));
			_isLaddering = false;
			SetGravity(1);
			_state->SetState(RIGHT_IDLE);
		}
		
		//위
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x, _trans->GetPos().y - _moveSpeedY));
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x, _trans->GetPos().y - _moveSpeedY));
		}

		//아래
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x, _trans->GetPos().y + _moveSpeedY));
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x, _trans->GetPos().y + _moveSpeedY));
		}

		_physics->SetBodyPosition();
	}
	else if (!_isLaddering)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			NormalMove(Vector2::b2Left, _moveSpeedX);
			_state->SetState(LEFT_IDLE);
			cout << _state->GetState() << endl;
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			if (_isPush && _isGround)
			{
				_state->SetState(LEFT_PUSH);

			}
			else
			{
				if (!_isFloating)
					_state->SetState(LEFT_MOVE);
			}

			if(_isFloating)
				NormalMove(Vector2::b2Left, _moveSpeedX);
			else
				SlowMove(Vector2::b2Left, _moveSpeedX);


			cout << _state->GetState() << endl;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_state->SetState(LEFT_IDLE);
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Zero);
			cout << _state->GetState() << endl;
		}

		//오른쪽
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			NormalMove(Vector2::b2Right, _moveSpeedX);
			cout << _state->GetState() << endl;

			_state->SetState(RIGHT_IDLE);
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			if (_isPush && _isGround)
			{
				_state->SetState(RIGHT_PUSH);
			}
			else
			{
				if(!_isFloating)
					_state->SetState(RIGHT_MOVE);

				if (_state->GetState() == RIGHT_SPECIAL2)
					_state->SetState(EXTRA1);
			}

			if (_isFloating)
				NormalMove(Vector2::b2Right, _moveSpeedX);
			else
				SlowMove(Vector2::b2Right, _moveSpeedX);
			cout << _state->GetState() << endl;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_state->SetState(RIGHT_IDLE);
			_physics->GetBody()->SetLinearVelocity(Vector2::b2Zero);
			cout << _state->GetState() << endl;
		}

		//위
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (_isLadder)
			{
				_isLaddering = true;
				SetGravity(0);
				_trans->pos.x = _LadderPos.x;
				_state->SetState(LADDER);
				_physics->SetBodyPosition();
				_physics->GetBody()->SetLinearVelocity(Vector2::b2Zero);
			}
		}

		_trans->SetPos(_physics->GetBodyPosition());
	}


}

void Character::NormalMove(b2Vec2 b2v, float power)
{
	_physics->ApplyForce(b2v * power);
}

void Character::SlowMove(b2Vec2 b2v, float power)
{
	_physics->GetBody()->SetLinearVelocity(b2v * (power - 1));
}

void Character::PosCorrection(Object* obj)
{
	//위치 보정...
	//_trans->SetPos(_trans->GetPos())
	//float xx = _trans->GetPos().x - obj->GetTrans()->GetPos.x;

	//_trans->SetPos(Vector2(_trans->GetPos().x + xx, _trans->GetPos().y));
}

void Character::CheckLR()
{
	if (_state->GetState() == LEFT_IDLE || _state->GetState() == LEFT_MOVE)
		_state->SetState(LEFT_FLOATING);
	else if (_state->GetState() == RIGHT_IDLE || _state->GetState() == RIGHT_MOVE)
		_state->SetState(RIGHT_FLOATING);
}

void Character::ChangeImage(string key)
{
	 _graphic->SetImgName(key);
}
