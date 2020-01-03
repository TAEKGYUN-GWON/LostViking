#include "stdafx.h"
#include "UIManager.h"
#include"Floor.h"
#include"Barrier.h"
#include "PhysicsBodyComponent.h"
#include "Ladder.h"
#include"GraphicComponent.h"
#include"UnGravityScript.h"


UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UIManager::Init()
{
	GRAPHICMANAGER->AddImage("UI", L"img/background/UI.png");
	GRAPHICMANAGER->AddImage("bg", L"img/background/Background2.png");

	GRAPHICMANAGER->AddImage("bLive", L"img/background/BaleogLive.png");
	GRAPHICMANAGER->AddImage("bDead", L"img/background/BaleogDead.png");
	GRAPHICMANAGER->AddImage("bDeactive", L"img/background/BaleogDeactivate.png");

	GRAPHICMANAGER->AddImage("eLive", L"img/background/ErikLive.png");
	GRAPHICMANAGER->AddImage("eDead", L"img/background/ErikDead.png");
	GRAPHICMANAGER->AddImage("eDeactive", L"img/background/ErikDeactivate.png");

	GRAPHICMANAGER->AddImage("oLive", L"img/background/OlafLive.png");
	GRAPHICMANAGER->AddImage("oDead", L"img/background/OlafDead.png");
	GRAPHICMANAGER->AddImage("oDeactive", L"img/background/OlafDeactivate.png");

	GRAPHICMANAGER->AddFrameImage("검빨 가로", L"img/background/twinkle/검빨 가로.png", 6, 1);
	GRAPHICMANAGER->AddFrameImage("검빨 세로", L"img/background/twinkle/검빨 세로.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("검빨", L"img/background/twinkle/검빨.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("검빨 매트릭스", L"img/background/twinkle/검빨 매트릭스.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("검빨 매트릭스", L"img/background/twinkle/검빨 매트릭스.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("줄", L"img/background/twinkle/일 자 두 줄과 네모 하나가 셋.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("검파 매트릭스", L"img/background/twinkle/검파 매트릭스.png", 6, 1);

	curFrameX4 = curFrameX6 = 0;
	count = 0;

	//for (int i = 0; i < 8; i++)
	//{
	//	Wall* floor = new Floor;
	//	floor->Init();
	//	floor->SetScale(350.f, 100);
	//	floor->SetPos(floor->GetScale().x / 2 + i * floor->GetScale().x-20, 695);
	//	floor->AddPbody();
	//	_vWalls.push_back(floor);

	//}
	{
		Wall* floor = new Floor;
		floor->SetScale(2761.f, 90);
		floor->SetPos(floor->GetScale().x / 2 -6, 697);
		floor->AddPbody();
		_vWalls.push_back(floor);
	}
	{
		Barrier* barrier = new Barrier;
		barrier->SetScale(50, 2370.f);
		barrier->SetPos(barrier->GetScale().x / 2, barrier->GetScale().y / 2);
		barrier->AddPbody();
		_vWalls.push_back(barrier);
	}
	{
		Barrier* barrier = new Barrier;
		barrier->SetScale(50, 512);
		barrier->SetPos(685, barrier->GetScale().y / 2);
		barrier->AddPbody();
		_vWalls.push_back(barrier);
	}
	{
		Barrier* barrier = new Barrier;
		barrier->SetScale(50, 250);
		barrier->SetPos(730, barrier->GetScale().y / 2);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Barrier* barrier2 = new Barrier;
		barrier2->SetScale(50, 468);
		barrier2->SetPos(1291, 275);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);

		Wall* floor1 = new Floor;
		floor1->SetScale(180, 45);
		floor1->SetPos(800, 255.5f);
		floor1->AddPbody();
		_vWalls.push_back(floor1);

		Wall* floor2 = new Floor;
		floor2->SetScale(709, 45);
		floor2->SetPos(1334.5f, 255.5f);
		floor2->AddPbody();
		_vWalls.push_back(floor2);

		Wall* Ceiling = new Floor;
		Ceiling->SetScale(1500, 40);
		Ceiling->SetPos(1424.5f, 22.5f);
		Ceiling->AddPbody();
		_vWalls.push_back(Ceiling);
	}

	{
		Wall* floor = new Floor;
		floor->SetScale(330, 45);
		floor->SetPos(1942.5f, 255.5f);
		floor->AddPbody();
		_vWalls.push_back(floor);

		Barrier* barrier = new Barrier;
		barrier->SetScale(50, 464);
		barrier->SetPos(2129, 234);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

	}
	{
		Wall* Ceiling = new Floor;
		Ceiling->SetScale(818, 45);
		Ceiling->SetPos(2556.f, 205.5f);
		Ceiling->AddPbody();
		_vWalls.push_back(Ceiling);

		Barrier* barrier = new Barrier;
		barrier->SetScale(50, 2370);
		barrier->SetPos(2972, 1185);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Barrier* barrier2 = new Barrier;
		barrier2->SetScale(140, 1533);
		barrier2->SetPos(2920, 1420.5f);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);

		Barrier* barrier3 = new Barrier;
		barrier3->SetScale(47, 320);
		barrier3->SetPos(2532.5f, 816);
		barrier3->AddPbody();
		_vWalls.push_back(barrier3);

		Barrier* barrier4 = new Barrier;
		barrier4->SetScale(47, 702);
		barrier4->SetPos(2734, 1562);
		barrier4->AddPbody();
		_vWalls.push_back(barrier4);
	}
	{
		Wall* Ceiling = new Floor;
		Ceiling->SetScale(650, 45);
		Ceiling->SetPos(2430, 954.5f);
		Ceiling->AddPbody();
		_vWalls.push_back(Ceiling);

		Barrier* barrier = new Barrier;
		barrier->SetScale(48, 248);
		barrier->SetPos(2127, 853);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Wall* floor = new Floor;
		floor->SetScale(467, 45);
		floor->SetPos(2524.5f, 1187.5f);
		floor->AddPbody();
		_vWalls.push_back(floor);

		Wall* floor2 = new Floor;
		floor2->SetScale(93, 45);
		floor2->SetPos(2150.f, 1187.5f);
		floor2->AddPbody();
		_vWalls.push_back(floor2);
	}

	{

		Barrier* barrier = new Barrier;
		barrier->SetScale(45, 301);
		barrier->SetPos(2360.5f, 1362.5f);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Barrier* barrier2 = new Barrier;
		barrier2->SetScale(44, 575);
		barrier2->SetPos(1567, 1250.5f);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);

		Wall* floor = new Floor;
		floor->SetScale(808, 46);
		floor->SetPos(1947, 1515);
		floor->AddPbody();
		_vWalls.push_back(floor);

		Wall* floor2 = new Floor;
		floor2->SetScale(1307, 44);
		floor2->SetPos(935.5f, 953);
		floor2->AddPbody();
		_vWalls.push_back(floor2);

		Wall* floor3 = new Floor;
		floor3->SetScale(148, 43);
		floor3->SetPos(116, 953);
		floor3->AddPbody();
		_vWalls.push_back(floor3);

	}

	{

		Wall* Ceiling = new Floor;
		Ceiling->SetScale(657, 45);
		Ceiling->SetPos(2386.5f, 1888.5f);
		Ceiling->AddPbody();
		_vWalls.push_back(Ceiling);

		Wall* Ceiling2 = new Floor;
		Ceiling2->SetScale(279, 45);
		Ceiling2->SetPos(1544.5f, 1888.5f);
		Ceiling2->AddPbody();
		_vWalls.push_back(Ceiling2);

		Barrier* barrier2 = new Barrier;
		barrier2->SetScale(45, 191);
		barrier2->SetPos(1426.5f, 2006.5f);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);

		Wall* floor = new Floor;
		floor->SetScale(1362, 91);
		floor->SetPos(2077, 2144.5f);
		floor->AddPbody();
		_vWalls.push_back(floor);
	}
	{
		Wall* barrier = new Barrier;
		barrier->SetScale(47, 383);
		barrier->SetPos(119.5f, 1167.5f);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Wall* barrier2 = new Barrier;
		barrier2->SetScale(50, 368);
		barrier2->SetPos(355, 1163);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);

		Wall* Ceiling = new Floor;
		Ceiling->SetScale(139, 48);
		Ceiling->SetPos(72.5f, 1374);
		Ceiling->AddPbody();
		_vWalls.push_back(Ceiling);

		Wall* Ceiling2 = new Floor;
		Ceiling2->SetScale(656, 48);
		Ceiling2->SetPos(658, 1372);
		Ceiling2->AddPbody();
		_vWalls.push_back(Ceiling2);


	}
	{
		Wall* floor = new Floor;
		floor->SetScale(656, 44);
		floor->SetPos(374, 1607);
		floor->AddPbody();
		_vWalls.push_back(floor);

		Wall* floor2 = new Floor;
		floor2->SetScale(190, 45);
		floor2->SetPos(892, 1607.5f);
		floor2->AddPbody();
		_vWalls.push_back(floor2);

		Wall* barrier = new Barrier;
		barrier->SetScale(49, 232);
		barrier->SetPos(1007.5f, 1469);
		barrier->AddPbody();
		_vWalls.push_back(barrier);
	}

	{
		Wall* Ceiling = new Floor;
		Ceiling->SetScale(95, 47);
		Ceiling->SetPos(937.5f, 1841.5f);
		Ceiling->AddPbody();
		_vWalls.push_back(Ceiling);

		Wall* Ceiling2 = new Floor;
		Ceiling2->SetScale(652, 48);
		Ceiling2->SetPos(376, 1842);
		Ceiling2->AddPbody();
		_vWalls.push_back(Ceiling2);

		Wall* barrier = new Barrier;
		barrier->SetScale(47, 232);
		barrier->SetPos(913.5f, 1748);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Wall* barrier2 = new Barrier;
		barrier2->SetScale(45, 279);
		barrier2->SetPos(680.5f, 1724.5f);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);

		Wall* barrier3 = new Barrier;
		barrier3->SetScale(48, 469);
		barrier3->SetPos(1007, 2076.5f);
		barrier3->AddPbody();
		_vWalls.push_back(barrier3);
	}
	{
		Wall* floor = new Floor;
		floor->SetScale(752, 48);
		floor->SetPos(612, 2076);
		floor->AddPbody();
		_vWalls.push_back(floor);

		Wall* floor2 = new Floor;
		floor2->SetScale(110, 48);
		floor2->SetPos(85.f, 2076);
		floor2->AddPbody();
		_vWalls.push_back(floor2);

		Wall* floor3 = new Floor;
		floor3->SetScale(949, 53);
		floor3->SetPos(516.5f, 2311.5f);
		floor3->AddPbody();
		_vWalls.push_back(floor3);

		Wall* barrier = new Barrier;
		barrier->SetScale(47, 92);
		barrier->SetPos(306.5f, 1866);
		barrier->AddPbody();
		_vWalls.push_back(barrier);

		Wall* barrier2 = new Barrier;
		barrier2->SetScale(46, 85);
		barrier2->SetPos(680, 2102.5f);
		barrier2->AddPbody();
		_vWalls.push_back(barrier2);
	}


	{
		Wall* barrier = new Barrier;
		barrier->SetScale(25, 71);
		barrier->SetPos(2744.5f, 615.5f);
		barrier->AddPbody();
		barrier->GetGraphic()->SetRectColor(Brush_type::BLACK);
		barrier->SetName("eBarrier");
		barrier->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(barrier);

		Wall* barrier2 = new Barrier;
		barrier2->SetScale(22, 50);
		barrier2->SetPos(1582, 906);
		barrier2->AddPbody();
		barrier->GetGraphic()->SetRectColor(Brush_type::BLACK);
		barrier2->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		barrier2->SetName("eBarrier");
		_vWalls.push_back(barrier2);
	}

	{
		Ladder* ladder1 = new Ladder;
		ladder1->SetPos(937, 439.5f);
		ladder1->SetScale(90, 423);
		ladder1->SetName("Ladder1");
		ladder1->AddPbody();
		ladder1->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(ladder1);

		Ladder* ladder2 = new Ladder;
		ladder2->SetPos(1729, 439.5f);
		ladder2->SetScale(90, 423);
		ladder2->SetName("Ladder2");
		ladder2->AddPbody();
		ladder2->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(ladder2);

		Ladder* ladder3 = new Ladder;
		ladder3->SetPos(237, 1258);
		ladder3->SetScale(95, 658);
		ladder3->SetName("Ladder3");
		ladder3->AddPbody();
		ladder3->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(ladder3);

		Ladder* ladder4 = new Ladder;
		ladder4->SetPos(2244.5f, 1326.5f);
		ladder4->SetScale(95, 330);
		ladder4->SetName("Ladder4");
		ladder4->AddPbody();
		ladder4->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(ladder4);

		Ladder* ladder5 = new Ladder;
		ladder5->SetPos(751.5f, 1818.5f);
		ladder5->SetScale(95, 467);
		ladder5->SetName("Ladder5");
		ladder5->AddPbody();
		ladder5->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(ladder5);

		Ladder* ladder6 = new Ladder;
		ladder6->SetPos(189.5f, 2168.5f);
		ladder6->SetScale(95, 235);
		ladder6->SetName("Ladder6");
		ladder6->AddPbody();
		ladder6->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
		_vWalls.push_back(ladder6);

	}
	GRAPHICMANAGER->AddFrameImage("UnGravity", L"img/background/twinkle/중력 화살표.png", 4, 1);
	Ladder* unGravity = new Ladder;
	unGravity->SetPos(1684, 1115);
	unGravity->SetScale(188, 748);
	unGravity->SetName("UnGravity");
	unGravity->GetGraphic()->Init(true, true);
	unGravity->GetGraphic()->SetImgName("UnGravity");
	unGravity->GetGraphic()->SetPivot(PIVOT::CENTER);
	unGravity->AddPbody();
	unGravity->getPbody()->GetBody()->GetFixtureList()->SetSensor(true);
	unGravity->AddComponent<UnGravityScript>();
	_vWalls.push_back(unGravity);

	camera = Vector2::zero;

	p = new Object;
	p->GetTrans()->SetPos(WINSIZEX / 2+100, WINSIZEY / 2);
	p->GetTrans()->SetScale(80,100);
	p->SetTag("Player");
	auto a = p->AddComponent<PhysicsBodyComponent>();
	//p->AddComponent<ButtonScript>();
	a->Init(DYNAMIC,0.5f);
	//a->GetBody()->SetGravityScale(0);
	//a->GetBody()->GetFixtureList()->SetSensor(true);

	
}

void UIManager::Release()
{
}

void UIManager::Update()
{
	Frame();
	//CameraMove();

	for (Wall* wall : _vWalls)
		wall->Update();

	PMove();

	
}

void UIManager::Render()
{
	if(KEYMANAGER->isToggleKey(VK_F2))
		GRAPHICMANAGER->FindImage("bg")->Render(Vector2(GRAPHICMANAGER->FindImage("bg")->GetWidth() / 2, GRAPHICMANAGER->FindImage("bg")->GetHeight() / 2));
	for (Wall* wall : _vWalls)
		wall->Render();
	DrawTwinkle();

	//GRAPHICMANAGER->FindImage("eLive")->RenderUI(Vector2(250, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("bLive")->RenderUI(Vector2(WINSIZEX / 2-105, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight()-20));
	//GRAPHICMANAGER->FindImage("oLive")->RenderUI(Vector2(WINSIZEX-458, WINSIZEY - GRAPHICMANAGER->FindImage("oLive")->GetHeight() - 20));
	//
	//GRAPHICMANAGER->FindImage("eDead")->RenderUI(Vector2(250, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("bDead")->RenderUI(Vector2(WINSIZEX / 2-105, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight()-20));
	//GRAPHICMANAGER->FindImage("oDead")->RenderUI(Vector2(WINSIZEX-458, WINSIZEY - GRAPHICMANAGER->FindImage("oLive")->GetHeight() - 20));
	//
	//GRAPHICMANAGER->FindImage("eDeactive")->RenderUI(Vector2(250, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("bDeactive")->RenderUI(Vector2(WINSIZEX / 2 - 105, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("oDeactive")->RenderUI(Vector2(WINSIZEX - 458, WINSIZEY - GRAPHICMANAGER->FindImage("oLive")->GetHeight() - 20));
	//
	//GRAPHICMANAGER->FindImage("UI")->RenderUI(Vector2(WINSIZEX / 2, WINSIZEY-GRAPHICMANAGER->FindImage("UI")->GetHeight()/2));
	p->Render();
}

void UIManager::Frame()
{
	count++;
	if (count > 5)
	{
		curFrameX4++;
		curFrameX6++;
		if (curFrameX4 >= 4) curFrameX4 = 0;
		if (curFrameX6 >= 6) curFrameX6 = 0;
		count = 0;
	}
}

void UIManager::DrawTwinkle()
{
	//검빨 가로
	{
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(2866.5f, 137), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(2524.5f, 836), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(2245.5f, 883), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(2617.5f, 1818), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(2617.5f, 2193), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(2617.5f, 2283), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(1962.5f, 2283), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(1310.5f, 1677), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(1402.5f, 1024), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(936.5f, 1305), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(656.5f, 1117), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 가로", Vector2(563.5f, 1771), curFrameX6, 0);
	}
	{
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(1823.5f, 137), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2057.5f, 441), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2896.5f, 418), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2291.5f, 744), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2665.5f, 839), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2944.5f, 932), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2665.5f, 1493), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2945.5f, 1540), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2945.5f, 1958), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2946.5, 2286), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2339.5f, 2286), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2335.5f, 2004), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2335.5f, 2004), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(2335.5f, 1070), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(794.5f, 835), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(468.5f, 835), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(839.5f, 1489), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(185.5f, 1959), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨", Vector2(749.5f, 2192), curFrameX4, 0);
	}
	{
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(562, 324), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(1076, 137), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(1216, 439), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(1590, 558), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(2244, 371), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(2897, 278), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(1216, 836), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(189, 836), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 매트릭스", Vector2(563, 2192), curFrameX4, 0);
	}
	{
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(185.5f, 553), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(1215.5f, 557), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(1590.5f, 440), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(1448.5f, 137), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(1729.5, 137), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(1729.5, 137), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(2243.5f, 510), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(2243.5f, 510), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(2243.5f, 159), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(2896.5f, 558), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(2524.5f, 1071), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(2710.5f, 2005), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(889.5f, 837), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(282.5f, 837), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(936.5f, 1491), curFrameX6, 0);
		GRAPHICMANAGER->DrawFrameImage("검파 매트릭스", Vector2(656.5f, 1958), curFrameX6, 0);
	}
	{
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2290.5f, 767.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2664.5f, 861.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2944.5f, 952.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2663.5f, 1512.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2944.5f, 1559.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2944.5f, 1981.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2944.5f, 2310.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2194.5f, 2214.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2194.5f, 2352.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2194.5f, 2352.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(2336.5f, 1747.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1964.5f, 1701.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1777.5f, 1701.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1448.5f, 1701.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1635.5f, 2263.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1635.5f, 2263.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1262.5f, 1794.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(1169.5f, 1888.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(422.5f, 1046.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("검빨 세로", Vector2(141.5f, 1702.5f), curFrameX4, 0);
	}
	{
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(2477.5f, 743.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(2944.5f, 1863.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(2944.5f, 1863.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(2430.5f, 1770.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(2057.5f, 1724.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(1777.5f, 1583.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(1356.5f, 1957.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(1076.5f, 2051.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(1076.5f, 1491.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(1263.5f, 1303.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(704.5f, 1303.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(983.5f, 1181.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(983.5f, 1181.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(796.5f, 1187.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(47.5f, 1258.5f), curFrameX4, 0);
		GRAPHICMANAGER->DrawFrameImage("줄", Vector2(327.5f, 1677.5f), curFrameX4, 0);
	}
}

void UIManager::CameraMove()
{
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		camera += Vector2::up* 5;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		camera += Vector2::down * 5;
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		camera += Vector2::left * 5;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		camera += Vector2::right * 5;
	}

	CAMERA->SetPosition(camera);
}

void UIManager::PMove()
{
	auto a = p->GetComponent<PhysicsBodyComponent>();
	a->GetBody()->SetFixedRotation(true);
		//fixrotation
	p->GetTrans()->SetPos(a->GetBodyPosition());
	//a->GetBody()->SetAngularVelocity(0);
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD4))
		a->ApplyForce(Vector2::b2Left * 8);
	if(KEYMANAGER->isStayKeyDown(VK_NUMPAD6))
		a->ApplyForce(Vector2::b2Right * 8);
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8))
		a->ApplyForce(Vector2::b2Up * 300);
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
		a->GetBody()->GetFixtureList()->SetFriction(10);
	p->Update();
	CAMERA->SetPosition(Vector2(p->GetTrans()->pos.x, p->GetTrans()->pos.y ));

	//a->GetBody()->SetGravityScale(0);
}
