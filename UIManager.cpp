#include "stdafx.h"
#include "UIManager.h"
#include"Floor.h"
#include"Barrier.h"
#include "PhysicsBodyComponent.h"
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
		barrier3->SetPos(2732.5f, 816);
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
		floor2->SetPos(56, 2076);
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


	p = new Object;
	p->GetTrans()->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	p->GetTrans()->SetScale(80,100);
	auto a = p->AddComponent<PhysicsBodyComponent>();
	a->Init(DYNAMIC,0.5f);
}

void UIManager::Release()
{
}

void UIManager::Update()
{
	for (Wall* wall : _vWalls)
		wall->Update();
	auto a = p->GetComponent<PhysicsBodyComponent>();
	a->GetBody()->SetFixedRotation(true);
		//fixrotation
	p->GetTrans()->SetPos(a->GetBodyPosition());
	//a->GetBody()->SetAngularVelocity(0);
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		a->GetBody()->SetLinearVelocity(Vector2::b2Left * 1);
	if(KEYMANAGER->isStayKeyDown(VK_RIGHT))
		a->ApplyForce(Vector2::b2Right * 8);
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		a->ApplyForce(Vector2::b2Up * 300);
	p->Update();
	//CAMERA->SetPosition(Vector2(p->GetTrans()->pos.x - WINSIZEX / 2, p->GetTrans()->pos.y - WINSIZEY / 2));
}

void UIManager::Render()
{
	if(KEYMANAGER->isToggleKey(VK_F2))
		GRAPHICMANAGER->FindImage("bg")->Render(Vector2(GRAPHICMANAGER->FindImage("bg")->GetWidth() / 2, GRAPHICMANAGER->FindImage("bg")->GetHeight() / 2));
	p->Render();
	for (Wall* wall : _vWalls)
		wall->Render();

	//GRAPHICMANAGER->FindImage("eLive")->RenderUI(Vector2(250, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("bLive")->RenderUI(Vector2(WINSIZEX / 2-105, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight()-20));
	//GRAPHICMANAGER->FindImage("oLive")->RenderUI(Vector2(WINSIZEX-458, WINSIZEY - GRAPHICMANAGER->FindImage("oLive")->GetHeight() - 20));

	//GRAPHICMANAGER->FindImage("eDead")->RenderUI(Vector2(250, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("bDead")->RenderUI(Vector2(WINSIZEX / 2-105, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight()-20));
	//GRAPHICMANAGER->FindImage("oDead")->RenderUI(Vector2(WINSIZEX-458, WINSIZEY - GRAPHICMANAGER->FindImage("oLive")->GetHeight() - 20));

	//GRAPHICMANAGER->FindImage("eDeactive")->RenderUI(Vector2(250, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("bDeactive")->RenderUI(Vector2(WINSIZEX / 2 - 105, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight() - 20));
	//GRAPHICMANAGER->FindImage("oDeactive")->RenderUI(Vector2(WINSIZEX - 458, WINSIZEY - GRAPHICMANAGER->FindImage("oLive")->GetHeight() - 20));

	//GRAPHICMANAGER->FindImage("UI")->RenderUI(Vector2(WINSIZEX / 2, WINSIZEY-GRAPHICMANAGER->FindImage("UI")->GetHeight()/2));
}
