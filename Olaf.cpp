#include "stdafx.h"
#include "Olaf.h"


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
}
