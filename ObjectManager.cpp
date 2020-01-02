#include "stdafx.h"
#include "ObjectManager.h"
#include"GraphicComponent.h"
void ObjectManager::Init()
{
	_isTest = true;

	Item* item;
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■토마토■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	item = new Tomato;
	item->Init(Vector2(420,530));
	_vItem.push_back(item);

	item = new Tomato;
	item->Init(Vector2(783, 192));
	_vItem.push_back(item);
	
	item = new Tomato;
	item->Init(Vector2(1486, 2050));
	_vItem.push_back(item);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■고기■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	item = new Meat;
	item->Init(Vector2(200, 200));
	_vItem.push_back(item);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■폭탄■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	item = new Bomb;
	item->Init(Vector2(2080, 208));
	_vItem.push_back(item);
	item = new Bomb;
	item->Init(Vector2(2080, 160));
	_vItem.push_back(item);
	
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■플라즈마■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	Plasma* plasma;
	plasma = new Plasma;
	plasma->Init(Vector2(865, 140));
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(1145, 140));
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(1987, 133));
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(2594, 1070));
	_vObject.push_back(plasma);
	plasma = new Plasma;
	plasma->Init(Vector2(2640, 1070));
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(2455, 2000));
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(1660, 2001));
	_vObject.push_back(plasma);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■포탑■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	RedgunTower* tower;
	tower = new RedgunTower;
	tower->Init(Vector2(90, 905),1);
	_vObject.push_back(tower);

	tower = new RedgunTower;
	tower->Init(Vector2(80, 1555),1);
	_vObject.push_back(tower);

	tower = new RedgunTower;
	tower->Init(Vector2(950, 2025),0);
	_vObject.push_back(tower);

	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■컴퓨터■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	Computer* com;
	com = new Computer;
	com->Init(Vector2(1870, 2068));
	_vObject.push_back(com);

	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■버튼■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	GRAPHICMANAGER->AddFrameImage("button", L"img/object/switch on off2.png", 3, 1);
	GRAPHICMANAGER->AddFrameImage("switch", L"img/object/switch_2.png", 3, 1);

	Button* button;
	button = new Button;
	button->Init(Vector2(1036, 156));
	button->GetGraphic()->SetImgName("button");
	_vObject.push_back(button);

	button = new Button;
	button->Init(Vector2(1942, 156));
	button->GetGraphic()->SetImgName("button");
	_vObject.push_back(button);

	button = new Button;
	button->Init(Vector2(2384, 2014));
	button->GetGraphic()->SetImgName("button");
	_vObject.push_back(button);


}

void ObjectManager::Release()
{

}

void ObjectManager::Update()
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_isTest = !_isTest;
		_vObject[0]->SetIsActive(_isTest);
	}
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Update();
	}
	for (int i = 0; i < _vObject.size(); i++)
	{
		_vObject[i]->Update();
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Render();
	}
	for (int i = 0; i < _vObject.size(); i++)
	{
		if(_vObject[i]->GetIsActive())
			_vObject[i]->Render();
	}
}
