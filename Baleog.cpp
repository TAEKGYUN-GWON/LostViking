#include "stdafx.h"
#include "Baleog.h"
#include "GraphicComponent.h"


Baleog::Baleog()
{
}


Baleog::~Baleog()
{
}

void Baleog::Init()
{
	GRAPHICMANAGER->AddFrameImage("Baleog_1_idle", L"img/Characters/Baleog/Baleog_1_idle.png", 2, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_2_move", L"img/Characters/Baleog/Baleog_2_movepng", 8, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_3_floating", L"img/Characters/Baleog/Baleog_3_floatingpng", 2, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_4_hit", L"img/Characters/Baleog/Baleog_4_hitpng", 1, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_5_ladder", L"img/Characters/Baleog/Baleog_5_ladderpng", 6, 1);
	GRAPHICMANAGER->AddFrameImage("Baleog_6_arrow", L"img/Characters/Baleog/Baleog_6_arrowpng", 8, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_7_sword", L"img/Characters/Baleog/Baleog_7_swordpng", 4, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_7_sword2", L"img/Characters/Baleog/Baleog_7_sword2png", 4, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_8_pushwall", L"img/Characters/Baleog/Baleog_8_pushwallpng", 4, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_9_death1", L"img/Characters/Baleog/Baleog_9_death1png", 6, 2);
	GRAPHICMANAGER->AddFrameImage("Baleog_9_death2", L"img/Characters/Baleog/Baleog_9_death2png", 2, 2);
}

void Baleog::Update()
{
}

void Baleog::ImageControl()
{

	switch (_state->GetState())
	{
		case RIGHT_IDLE:
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_1_idle");
			break;
		case LEFT_IDLE:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_1_idle");
			break;
		case RIGHT_MOVE:
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_2_move");
			break;
		case LEFT_MOVE:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_2_move");
			break;
		case RIGHT_DEATH: //�Ϲ����� ���� (����� EXTRA3)
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_9_death1");
			break;
		case LEFT_DEATH:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_9_death1");
			break;
		case RIGHT_PUSH:
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_8_pushwall");
			break;
		case LEFT_PUSH:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_8_pushwall");
			break;
		case RIGHT_HIT:
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_4_hit");
			break;
		case LEFT_HIT:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_4_hit");
			break;
		case RIGHT_FLOATING:
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_3_floating");
			break;
		case LEFT_FLOATING:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_3_floating");
			break;
		case RIGHT_SPECIAL1:  //Ȱ���
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_6_arrow");
			break;
		case LEFT_SPECIAL1:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_6_arrow");
			break;
		case RIGHT_SPECIAL2: //�� �ֵθ���, �� �ֵθ��� �Ǵٸ��� EXTRA1�� ����
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_7_sword");
			break;
		case LEFT_SPECIAL2:
			_graphic->SetFrameY(1);
			ChangeImage("Baleog_7_sword");
			break;
		case LADDER:
			//�̰� ���� �̹��� �����ؾ��ҵ�
			//��ٸ� ����⿡ ����� �� ���°� ���� ��� �̹��� �̻���
			_graphic->SetFrameY(0);
			ChangeImage("Baleog_5_ladder");
			break;
		case EXTRA1: //�� �ֵθ��� 2��° ���
			_graphic->SetFrameX(0);
			ChangeImage("Baleog_7_sword2");
			break;
		case EXTRA2: 
			_graphic->SetFrameX(1);
			ChangeImage("Baleog_7_sword2");
			break;
		case EXTRA3: //����� �״°�
			_graphic->SetFrameX(0);
			ChangeImage("Baleog_9_death2");
			break;
		case EXTRA4:
			_graphic->SetFrameX(1);
			ChangeImage("Baleog_9_death2");

	}
}
