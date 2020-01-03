#include "stdafx.h"
#include "Erik.h"
#include "GraphicComponent.h"

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

	super::Init(spawnX, spawnY);

}

void Erik::Update()
{
	super::Update();

	KeyControl();

	ImageControl();


}


void Erik::Render() 
{
	super::Render();


}

void Erik::KeyControl()
{
	if (_isLaddering) //�Ŵ޷� ���� ��
	{

	}
	else if (!_isLaddering) //�ȸŴ޷� ���� ��
	{
		if (_state->GetState() == RIGHT_MOVE)//�뽬
		{
			if (KEYMANAGER->isOnceKeyDown('d'))
			{
				_state->SetState(RIGHT_SPECIAL1);
				cout << _state->GetState() << endl;
			}
		}
		if (_state->GetState() == LEFT_MOVE)//�뽬
		{
			if (KEYMANAGER->isOnceKeyDown('d'))
			{
				_state->SetState(LEFT_SPECIAL1);
			}
		}
	}



	//super::KeyControl();
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
	case RIGHT_DEATH: //�Ϲ����� ���� (����� ���� ����)
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
	case RIGHT_SPECIAL1: //�뽬
		_graphic->SetFrameY(0);
		ChangeImage("eric_headbutt");
		break;
	case LEFT_SPECIAL1:
		_graphic->SetFrameY(1);
		ChangeImage("eric_headbutt");
		break;
	case LADDER:
		//�̰� ���� �̹��� �����ؾ��ҵ�
		//��ٸ� ����⿡ ����� �� ���°� ���� ��� �̹��� �̻���
		_graphic->SetFrameY(0);
		ChangeImage("eric_stepladder");
		break;
	case EXTRA1: //����� �״°�
		_graphic->SetFrameX(0);
		ChangeImage("eric_death2");
		break;
	case EXTRA2:
		_graphic->SetFrameX(1);
		ChangeImage("eric_death2");
		break;
	}
}


