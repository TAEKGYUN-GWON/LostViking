#include "stdafx.h"
#include "Olaf.h"
#include "GraphicComponent.h"

Olaf::Olaf()
{
}


Olaf::~Olaf()
{
}

void Olaf::Init()
{
	GRAPHICMANAGER->AddFrameImage("olaf_1_idle_shieldAhead", L"olaf_1_idle_shieldAhead.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_2_move_shieldAhead", L"olaf_2_move_shieldAhead.png", 8, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_2_move_shieldUp", L"olaf_2_move_shieldUp.png", 8, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_3_floating", L"olaf_3_floating.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_4_hit", L"olaf_4_hit.png", 1, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_5_ladder", L"olaf_5_ladder.png", 6, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_6_flyingdown", L"olaf_6_flyingdown.png", 4, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_7_shieldUp", L"olaf_7_shieldUp.png", 3, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_8_pushwall", L"olaf_8_pushwall.png", 4, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_9_death1", L"olaf_9_death1.png", 6, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_9_death2", L"olaf_9_death2.png", 2, 2);

}

void Olaf::Update()
{
}

void Olaf::ImageControl()
{

	switch (_state->GetState())
	{
	case RIGHT_IDLE:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_1_idle_shieldAhead"); 
		break;
	case LEFT_IDLE:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_1_idle_shieldAhead");
		break;
	case RIGHT_MOVE:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_2_move_shieldAhead");
		break;
	case LEFT_MOVE:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_2_move_shieldAhead");
		break;
	case RIGHT_DEATH:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_9_death1");
		break;
	case LEFT_DEATH:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_9_death1");
		break;
	case RIGHT_PUSH:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_8_pushwall");
		break;
	case LEFT_PUSH:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_8_pushwall");
		break;
	case RIGHT_HIT:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_4_hit");
		break;
	case LEFT_HIT:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_4_hit");
		break;
	case RIGHT_FLOATING:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_3_floating");
		break;
	case LEFT_FLOATING:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_3_floating");
		break;
	case RIGHT_SPECIAL1: //날아서 내려오기
		_graphic->SetFrameY(0);
		ChangeImage("olaf_6_flyingdown");
		break;
	case LEFT_SPECIAL1:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_6_flyingdown");
		break;
	case RIGHT_SPECIAL2: //방패 위로해서 발판되기
		_graphic->SetFrameY(0);
		ChangeImage("olaf_7_shieldUp");
		break;
	case LEFT_SPECIAL2:
		_graphic->SetFrameY(1);
		ChangeImage("olaf_7_shieldUp");
		break;
	case LADDER:
		_graphic->SetFrameY(0);
		ChangeImage("olaf_5_ladder");
		break;
	}

}
