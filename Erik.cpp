#include "stdafx.h"
#include "Erik.h"
#include "GraphicComponent.h"
#include "TransformComponent.h"

Erik::Erik()
{
}

Erik::~Erik()
{
}

void Erik::Init(float spawnX, float spawnY)
{

	GRAPHICMANAGER->AddFrameImage("eric_idle",L"img/Characters/Erik/eric_idle.png",2,2);
	GRAPHICMANAGER->AddFrameImage("eric_move",L"img/Characters/Erik/eric_move.png",8,2);
	GRAPHICMANAGER->AddFrameImage("eric_hitState",L"img/Characters/Erik/eric_hitState.png",1,2);
	GRAPHICMANAGER->AddFrameImage("eric_jump",L"img/Characters/Erik/eric_jump.png",4,2);
	GRAPHICMANAGER->AddFrameImage("eric_headbutt",L"img/Characters/Erik/eric_headbutt.png",8,2);
	GRAPHICMANAGER->AddFrameImage("eric_push",L"img/Characters/Erik/eric_push.png",4,2);
	GRAPHICMANAGER->AddFrameImage("eric_stepladder",L"img/Characters/Erik/eric_stepladder.png",4,1);
	GRAPHICMANAGER->AddFrameImage("eric_death1",L"img/Characters/Erik/eric_death1.png",7,2);
	GRAPHICMANAGER->AddFrameImage("eric_death2",L"img/Characters/Erik/eric_death2.png",2,2);

	_jumpPower = _gravity = 0;

	super::Init(spawnX, spawnY);

}

void Erik::Update()
{
	super::Update();

	KeyControl();
	StateControl();

	ImageControl();


}


void Erik::Render() 
{
	super::Render();


}

void Erik::KeyControl()
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
		if (KEYMANAGER->isOnceKeyDown(VK_UP) || KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_trans->SetPos(Vector2(_trans->GetPos().x, _trans->GetPos().y - _moveSpeedY));
		}

		//아래
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) || KEYMANAGER->isStayKeyDown(VK_DOWN))
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

			if (_isFloating)
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
				if (!_isFloating)
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

void Erik::StateControl()
{


	switch (_state->GetState())
	{
		case RIGHT_IDLE:
		
			break;
		case LEFT_IDLE:
		
			break;
		case RIGHT_MOVE:
		
			break;
		case LEFT_MOVE:
		
			break;
		case RIGHT_DEATH: //일반적인 죽음 (전기는 따로 있음)
	
			break;
		case LEFT_DEATH:
		
			break;
		case RIGHT_PUSH:
		
			break;
		case LEFT_PUSH:
	
			break;
		case RIGHT_HIT:
		
			break;
		case LEFT_HIT:
		
			break;
		case RIGHT_FLOATING:
		
			break;
		case LEFT_FLOATING:
		
			break;
		case RIGHT_SPECIAL1: //대쉬
		
			break;
		case LEFT_SPECIAL1:
		
			break;
		case LADDER:
	
			break;
		case EXTRA1: //전기로 죽는거
	
			break;
		case EXTRA2:

			break;
	}
}

void Erik::ImageControl()
{
	switch (_state->GetState())
	{
		case RIGHT_IDLE:
			_graphic->SetFrameY(0);
			ChangeImage("eric_idle");
			break;
		case LEFT_IDLE:
			_graphic->SetFrameY(1);
			ChangeImage("eric_idle");
			break;
		case RIGHT_MOVE:
			_graphic->SetFrameY(0);
			ChangeImage("eric_move");
			break;
		case LEFT_MOVE:
			_graphic->SetFrameY(1);
			ChangeImage("eric_move");
			break;
		case RIGHT_DEATH: //일반적인 죽음 (전기는 따로 있음)
			_graphic->SetFrameY(0);
			ChangeImage("eric_death1");
			break;
		case LEFT_DEATH:
			_graphic->SetFrameY(1);
			ChangeImage("eric_death1");
			break;
		case RIGHT_PUSH:
			_graphic->SetFrameY(0);
			ChangeImage("eric_push");
			break;
		case LEFT_PUSH:
			_graphic->SetFrameY(1);
			ChangeImage("eric_push");
			break;
		case RIGHT_HIT:
			_graphic->SetFrameY(0);
			ChangeImage("eric_hitState");
			break;
		case LEFT_HIT:
			_graphic->SetFrameY(1);
			ChangeImage("eric_hitState");
			break;
		case RIGHT_FLOATING:
			_graphic->SetFrameY(0);
			ChangeImage("eric_jump");
			break;
		case LEFT_FLOATING:
			_graphic->SetFrameY(1);
			ChangeImage("eric_jump");
			break;
		case RIGHT_SPECIAL1: //대쉬
			_graphic->SetFrameY(0);
			ChangeImage("eric_headbutt");
			break;
		case LEFT_SPECIAL1:
			_graphic->SetFrameY(1);
			ChangeImage("eric_headbutt");
			break;
		case LADDER:
			//이건 봐서 이미지 수정해야할듯
			//사다리 꼭대기에 닿았을 때 상태가 따로 없어서 이미지 이상함
			_graphic->SetFrameY(0);
			ChangeImage("eric_stepladder");
			break;
		case EXTRA1: //전기로 죽는거
			_graphic->SetFrameX(0);
			ChangeImage("eric_death2");
			break;
		case EXTRA2:
			_graphic->SetFrameX(1);
			ChangeImage("eric_death2");
			break;
	}
}


