#include "stdafx.h"
#include "Olaf.h"
#include "GraphicComponent.h"
#include "TransformComponent.h"

Olaf::Olaf()
{
}


Olaf::~Olaf()
{
}

void Olaf::Init(float spawnX, float spawnY)
{

	GRAPHICMANAGER->AddFrameImage("olaf_idle_shieldAhead", L"img/Characters/Olaf/olaf_1_idle_shieldAhead.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_move_shieldAhead", L"img/Characters/Olaf/olaf_2_move_shieldAhead.png", 8, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_move_shieldUp", L"img/Characters/Olaf/olaf_2_move_shieldUp.png", 8, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_floating", L"img/Characters/Olaf/olaf_3_floating.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_hit", L"img/Characters/Olaf/olaf_4_hit.png", 1, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_ladder", L"img/Characters/Olaf/olaf_5_laddering.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("olaf_flyingdown", L"img/Characters/Olaf/olaf_6_flyingdown.png", 4, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_shieldUp", L"img/Characters/Olaf/olaf_7_shieldUp.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_pushwall", L"img/Characters/Olaf/olaf_8_pushwall.png", 4, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_death1", L"img/Characters/Olaf/olaf_9_death1.png", 6, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_death2", L"img/Characters/Olaf/olaf_9_death2.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_death2", L"img/Characters/Olaf/olaf_9_death2.png", 2, 2);

	super::Init(spawnX, spawnY);

	SetShield();

}

void Olaf::Update()
{
	super::Update();

	
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

			if (_state->GetState() == LEFT_FLOATING || _state->GetState() == O_LEFT_SHIELD_CONTROL)
				_state->SetState(LEFT_IDLE);
			else if (_state->GetState() == RIGHT_FLOATING || _state->GetState() == O_RIGHT_SHIELD_CONTROL)
				_state->SetState(RIGHT_IDLE);

			cout << _state->GetState() << endl;
		}
	}


	KeyControl();

	ShieldMove();

	ShieldState();

	CAMERA->SetPosition(_trans->GetPos());

	ImageControl();




	for (int i = 0; i < _shields.size(); i++)
		_shields[i]->Update();
}

void Olaf::Render()
{
	super::Render();

	for (int i = 0; i < _shields.size(); i++)
	{
		if(_shields[i]->GetIsActive())
			_shields[i]->Render();
	}
}

void Olaf::ImageControl()
{

	switch (_state->GetState())
	{
	case RIGHT_IDLE:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_idle_shieldAhead");
		break;
	case LEFT_IDLE:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_idle_shieldAhead");
		break;
	case RIGHT_MOVE:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_move_shieldAhead");
		break;
	case LEFT_MOVE:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_move_shieldAhead");
		break;
	case RIGHT_DEATH: //일반적인 죽음 (전기는 따로 있음)
		_graphic->SetFrameY(0);
		ChangeImage("olaf_death1");
		break;
	case LEFT_DEATH:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_death1");
		break;
	case RIGHT_PUSH:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_pushwall");
		break;
	case LEFT_PUSH:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_pushwall");
		break;
	case RIGHT_HIT:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_hit");
		break;
	case LEFT_HIT:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_hit");
		break;
	case RIGHT_FLOATING:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_floating");
		break;
	case LEFT_FLOATING:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_floating");
		break;
	case RIGHT_SPECIAL1: //날아서 내려오기
		_graphic->SetFrameY(0);
		ChangeImage("olaf_flyingdown");
		break;
	case LEFT_SPECIAL1:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_flyingdown");
		break;
	case RIGHT_SPECIAL2: //방패 위로해서 발판되기
		_graphic->SetFrameY(0);
		ChangeImage("olaf_shieldUp");
		break;
	case LEFT_SPECIAL2:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_shieldUp");
		break;
	case LADDER:
		//이건 봐서 이미지 수정해야할듯
		//사다리 꼭대기에 닿았을 때 상태가 따로 없어서 이미지 이상함
		_graphic->SetFrameY(0);
		ChangeImage("olaf_ladder");
		break;
	case EXTRA1: //방패 머리위로 하고 MOVE RIGHT
		_graphic->SetFrameY(0);
		ChangeImage("olaf_move_shieldUp");
		break;
	case EXTRA2: //방패 머리위로 하고 MOVE LEFT
		_graphic->SetFrameY(1);
		ChangeImage("olaf_move_shieldUp");
		break;
	case EXTRA3:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_death2");
		break;
	case EXTRA4:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_death2");
		break;
	case O_LEFT_SHIELD_CONTROL:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_flyingdown");
		break;
	case O_RIGHT_SHIELD_CONTROL:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_flyingdown");
		break;
	}
	//keycontrol이랑 연계해서 상태 몇개 더 추가하는게 좋을 것 같음..

}

void Olaf::SetShield()
{
	_upShield = new Object();
	_upShield->SetTag("UpShield");
	_upShield->AddComponent<PhysicsBodyComponent>()->Init(STATIC,1.f);
	_upShield->GetTrans()->SetPos(_trans->GetPos().x, _trans->GetPos().y - 60);
	_upShield->GetTrans()->SetScale(80 , 10);
	_upShield->SetIsActive(false);

	_leftShield = new Object();
	_leftShield->SetTag("LeftShield");
	_leftShield->AddComponent<PhysicsBodyComponent>()->Init(STATIC, 1.f);
	_leftShield->GetTrans()->SetPos(_trans->GetPos().x - 60, _trans->GetPos().y);
	_leftShield->GetTrans()->SetScale(10, 80);
	_upShield->SetIsActive(false);

	_rightShield = new Object();
	_rightShield->SetTag("RightShield");
	_rightShield->AddComponent<PhysicsBodyComponent>()->Init(STATIC, 1.f);
	_rightShield->GetTrans()->SetPos(_trans->GetPos().x + 60, _trans->GetPos().y);
	_rightShield->GetTrans()->SetScale(10, 80);

	_shields.push_back(_upShield);
	_shields.push_back(_leftShield);
	_shields.push_back(_rightShield);

}

void Olaf::ShieldMove()
{
	_upShield->GetTrans()->SetPos(_trans->GetPos().x, _trans->GetPos().y - 60);
	_leftShield->GetTrans()->SetPos(_trans->GetPos().x - 60, _trans->GetPos().y);
	_rightShield->GetTrans()->SetPos(_trans->GetPos().x + 60, _trans->GetPos().y);
	
}

void Olaf::KeyControl()
{
	if (_isLaddering)
	{
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_state->SetState(LADDER);
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_state->SetState(LADDER);
		}

		//왼쪽
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x - _moveSpeedX, _trans->GetPos().y));
			_isLaddering = false;
			SetGravity(1);

			//if (_state->GetState() != LEFT_SPECIAL2)
				_state->SetState(LEFT_FLOATING);
		}

		//오른쪽
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x + _moveSpeedX, _trans->GetPos().y));
			_isLaddering = false;
			SetGravity(1);
			_state->SetState(RIGHT_FLOATING);
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


			if (_state->GetState() == O_LEFT_SHIELD_CONTROL || _state->GetState() == O_RIGHT_SHIELD_CONTROL)
				_state->SetState(O_LEFT_SHIELD_CONTROL);
			else if (_state->GetState() != EXTRA2 && _state->GetState() != LEFT_SPECIAL2)
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
				/*if (!_isFloating)
					_state->SetState(LEFT_MOVE); */
				if(_state->GetState() == O_RIGHT_SHIELD_CONTROL)
					_state->SetState(O_LEFT_SHIELD_CONTROL);
				else if (_state->GetState() == LEFT_SPECIAL2 || _state->GetState() == EXTRA2)
					_state->SetState(EXTRA2);
				else if (!_isFloating)
					_state->SetState(LEFT_MOVE);
			}

			if (_isFloating && _state->GetState() != O_LEFT_SHIELD_CONTROL && _state->GetState() != O_RIGHT_SHIELD_CONTROL)
				NormalMove(Vector2::b2Left, _moveSpeedX);
			else
				SlowMove(Vector2::b2Left, _moveSpeedX);


			cout << _state->GetState() << endl;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			//_state->SetState(LEFT_IDLE);

			 if (_state->GetState() == O_LEFT_SHIELD_CONTROL)
				_state->SetState(O_LEFT_SHIELD_CONTROL);
			else if (_state->GetState() == EXTRA2)
				_state->SetState(LEFT_SPECIAL2); 
			else
				_state->SetState(LEFT_IDLE);

			_physics->GetBody()->SetLinearVelocity(Vector2::b2Zero);
			cout << _state->GetState() << endl;
		}

		//오른쪽
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			NormalMove(Vector2::b2Right, _moveSpeedX);
			cout << _state->GetState() << endl;

			if (_state->GetState() == O_RIGHT_SHIELD_CONTROL)
				_state->SetState(O_RIGHT_SHIELD_CONTROL);
			else if (_state->GetState() != EXTRA1 && _state->GetState() != RIGHT_SPECIAL2)
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
				if (_state->GetState() == O_LEFT_SHIELD_CONTROL)
					_state->SetState(O_RIGHT_SHIELD_CONTROL);
				else if (_state->GetState() == RIGHT_SPECIAL2 || _state->GetState() == EXTRA1)
					_state->SetState(EXTRA1);
				else if (!_isFloating)
					_state->SetState(RIGHT_MOVE);
			}

			if (_isFloating && _state->GetState() != O_LEFT_SHIELD_CONTROL && _state->GetState() != O_RIGHT_SHIELD_CONTROL)
				NormalMove(Vector2::b2Right, _moveSpeedX);
			else
				SlowMove(Vector2::b2Right, _moveSpeedX);
			cout << _state->GetState() << endl;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			if (_state->GetState() == O_RIGHT_SHIELD_CONTROL)
				_state->SetState(O_RIGHT_SHIELD_CONTROL);
			else if (_state->GetState() == EXTRA1)
				_state->SetState(RIGHT_SPECIAL2);
			else
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

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		ShildChange();
	}
	
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		ShildChange();
	}
		
}

void Olaf::ShildChange()
{
	if (_state->GetState() == RIGHT_IDLE || _state->GetState() == RIGHT_MOVE)
	{
		_state->SetState(RIGHT_SPECIAL2);
		cout << _state->GetState() << endl;
	}
	else if (_state->GetState() == LEFT_IDLE || _state->GetState() == LEFT_MOVE)
	{
		_state->SetState(LEFT_SPECIAL2);
		cout << _state->GetState() << endl;
	}
	else if (_state->GetState() == RIGHT_SPECIAL2)
	{
		_state->SetState(RIGHT_IDLE);
	}
	else if (_state->GetState() == LEFT_SPECIAL2)
	{
		_state->SetState(LEFT_IDLE);
	}
	else if (_state->GetState() == EXTRA1)
	{
		_state->SetState(RIGHT_MOVE);
	}
	else if (_state->GetState() == EXTRA2)
	{
		_state->SetState(LEFT_MOVE);
	}
	else if (_state->GetState() == RIGHT_FLOATING)
	{
		_state->SetState(O_RIGHT_SHIELD_CONTROL);
	}
	else if (_state->GetState() == LEFT_FLOATING)
	{
		_state->SetState(O_LEFT_SHIELD_CONTROL);
	}
	else if (_state->GetState() == O_RIGHT_SHIELD_CONTROL)
	{
		_state->SetState(RIGHT_FLOATING);
	}
	else if (_state->GetState() == O_LEFT_SHIELD_CONTROL)
	{
		_state->SetState(LEFT_FLOATING);
	}
	
}

void Olaf::ShieldState()
{
	
	if (_state->GetState() == RIGHT_IDLE || _state->GetState() == RIGHT_MOVE || _state->GetState() == RIGHT_FLOATING)
	{
		_upShield->SetIsActive(false);
		_leftShield->SetIsActive(false);
		_rightShield->SetIsActive(true);
		_isShiledUp = false;
	}
	if (_state->GetState() == LEFT_IDLE || _state->GetState() == LEFT_MOVE || _state->GetState() == LEFT_FLOATING)
	{
		_upShield->SetIsActive(false);
		_leftShield->SetIsActive(true);
		_rightShield->SetIsActive(false);
		_isShiledUp = false;
	}
	if (_state->GetState() == RIGHT_SPECIAL2 || _state->GetState() == LEFT_SPECIAL2
		|| _state->GetState() == EXTRA1 || _state->GetState() == EXTRA2
		|| _state->GetState() == O_RIGHT_SHIELD_CONTROL || _state->GetState() == O_LEFT_SHIELD_CONTROL)
	{
		_upShield->SetIsActive(true);
		_leftShield->SetIsActive(false);
		_rightShield->SetIsActive(false);
		_isShiledUp = true;
	}

	if (_state->GetState() == LADDER)
	{
		_upShield->GetComponent<PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(false);
	}
	else
	{
		if(_isShiledUp)
			_upShield->GetComponent<PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(true);
	}
}