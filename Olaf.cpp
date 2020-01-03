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
	GRAPHICMANAGER->AddFrameImage("olaf_shieldUp", L"img/Characters/Olaf/olaf_7_shieldUp.png", 3, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_pushwall", L"img/Characters/Olaf/olaf_8_pushwall.png", 4, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_death1", L"img/Characters/Olaf/olaf_9_death1.png", 6, 2);
	GRAPHICMANAGER->AddFrameImage("olaf_death2", L"img/Characters/Olaf/olaf_9_death2.png", 2, 2);

	super::Init(spawnX, spawnY);

	SetShield();

}

void Olaf::Update()
{
	super::Update();

	ShieldMove();

	ImageControl();

	for (int i = 0; i < _shields.size(); i++)
		_shields[i]->Update();
}

void Olaf::Render()
{
	super::Render();

	for (int i = 0; i < _shields.size(); i++)
	{
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
			_graphic->SetFrameX(0);
			ChangeImage("olaf_move_shieldUp");
			break;
		case EXTRA2: //방패 머리위로 하고 MOVE LEFT
			_graphic->SetFrameX(1);
			ChangeImage("olaf_move_shieldUp");
			break;
		case EXTRA3:
			_graphic->SetFrameX(0);
			ChangeImage("olaf_death2");
			break;
		case EXTRA4:
			_graphic->SetFrameX(1);
			ChangeImage("olaf_death2");

	}
	//keycontrol이랑 연계해서 상태 몇개 더 추가하는게 좋을 것 같음..

}

void Olaf::SetShield()
{
	_upShield = new Object();
	_upShield->SetTag("UpShield");
	_upShield->AddComponent<PhysicsBodyComponent>()->Init(DYNAMIC,1.f);
	_upShield->GetTrans()->SetPos(_trans->GetPos().x, _trans->GetPos().y - 100);
	_upShield->GetTrans()->SetScale(10 , 10);

	_shields.push_back(_upShield);
}

void Olaf::ShieldMove()
{
	_upShield->GetTrans()->SetPos(_trans->GetPos().x, _trans->GetPos().y - 50);
}