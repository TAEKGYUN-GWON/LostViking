#include "stdafx.h"
#include "UIManager.h"
#include"GraphicComponent.h"

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
	test = new Wall;
	test->Init();
	auto a = test->GetComponent<GraphicComponent>();
	a->SetStrokeWidth(4.f);
	a->SetRectColor(BRUSH_TYPE::AQUAMARINE);
}

void UIManager::Release()
{
}

void UIManager::Update()
{
	test->Update();
}

void UIManager::Render()
{
	if(KEYMANAGER->isToggleKey(VK_F2))
		//GRAPHICMANAGER->FindImage("bg")->Render(Vector2(GRAPHICMANAGER->FindImage("bg")->GetWidth() / 2, GRAPHICMANAGER->FindImage("bg")->GetHeight() / 2));
		GRAPHICMANAGER->DrawImage("bg", Vector2(0, 0), LEFT_TOP);

	test->Render();
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
