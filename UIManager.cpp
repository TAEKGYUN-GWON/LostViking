#include "stdafx.h"
#include "UIManager.h"


UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UIManager::Init()
{
	GRAPHICMANAGER->AddImage("UI", L"img/background/UI.png");
	GRAPHICMANAGER->AddImage("bg", L"img/background/Background.png");

	GRAPHICMANAGER->AddImage("bLive", L"img/background/BaleogLive.png");
	//GRAPHICMANAGER->AddImage("bDead", L"img/background/BaleogDead.png");
	//GRAPHICMANAGER->AddImage("bDeactive", L"img/background/BaleogDeactive.png");

	//GRAPHICMANAGER->AddImage("eLive", L"img/background/ErikLive.png");
	//GRAPHICMANAGER->AddImage("eDead", L"img/background/ErikDead.png");
	//GRAPHICMANAGER->AddImage("eDeactive", L"img/background/ErikDeactive.png");

	//GRAPHICMANAGER->AddImage("oLive", L"img/background/OlafLive.png");
	//GRAPHICMANAGER->AddImage("oDead", L"img/background/OlafDead.png");
	//GRAPHICMANAGER->AddImage("oDeactive", L"img/background/OlafDeactive.png");

}

void UIManager::Update()
{
}

void UIManager::Render()
{
	GRAPHICMANAGER->FindImage("bg")->Render(Vector2(GRAPHICMANAGER->FindImage("bg")->GetWidth() / 2, GRAPHICMANAGER->FindImage("bg")->GetHeight() / 2));
	GRAPHICMANAGER->FindImage("UI")->Render(Vector2(WINSIZEX / 2, WINSIZEY-GRAPHICMANAGER->FindImage("UI")->GetHeight()/2));
	GRAPHICMANAGER->FindImage("bLive")->Render(Vector2(WINSIZEX / 2-100, WINSIZEY - GRAPHICMANAGER->FindImage("bLive")->GetHeight()-20));
}
