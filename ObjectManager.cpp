#include "stdafx.h"
#include "ObjectManager.h"
#include "GraphicComponent.h"
#include "ButtonScript.h"

void ObjectManager::Init()
{
	_isTest = true;

	Item* item;
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■토마토■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	/*item = new Tomato;
	item->Init(Vector2(420,530));
	_vItem.push_back(item);*/

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
	plasma->SetName("Plasma1");
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(1145, 140));
	plasma->SetName("Plasma2");
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(1987, 133));
	plasma->SetName("Plasma3");
	_vObject.push_back(plasma);
	
	plasma = new Plasma;
	plasma->Init(Vector2(2594, 1070));
	plasma->SetName("Plasma4");
	_vObject.push_back(plasma);
	
	plasma = new Plasma;
	plasma->Init(Vector2(2640, 1070));
	plasma->SetName("Plasma5");
	_vObject.push_back(plasma);
	
	plasma = new Plasma;
	plasma->Init(Vector2(2454, 2004));
	plasma->SetName("Plasma6");
	_vObject.push_back(plasma);
	
	plasma = new Plasma;
	plasma->Init(Vector2(1660, 2001));
	plasma->SetName("Plasma7");
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
	GRAPHICMANAGER->AddFrameImage("button", L"img/object/switch on off.png", 2, 1);
	GRAPHICMANAGER->AddFrameImage("switch", L"img/object/switch_2.png", 2, 1);
	
	Button* button;
	button = new Button;
	button->Init(Vector2(1036, 156));
	button->GetGraphic()->Init(true);
	button->SetName("Button1");
	button->GetGraphic()->SetPivot(CENTER);
	button->GetGraphic()->SetImgName("button");
	button->GetGraphic()->SetFPS(0.7f);
	button->GetTrans()->scale = Vector2(button->GetGraphic()->GetGraphic()->GetFrameWidth(),
		button->GetGraphic()->GetGraphic()->GetFrameHeight());
	button->SetPhysics(button->AddComponent<PhysicsBodyComponent>());
	button->GetPhysics()->Init(STATIC, 1, 1.0f, 0.0f, false, true);
	button->AddComponent<ButtonScript>();
	_vObject.push_back(button);

	button = new Button;
	button->Init(Vector2(1942, 156));
	button->GetGraphic()->Init(true);
	button->SetName("Button2");
	button->GetGraphic()->SetPivot(CENTER);
	button->GetGraphic()->SetImgName("button");
	button->GetGraphic()->SetFPS(0.7f);
	button->GetTrans()->scale = Vector2(button->GetGraphic()->GetGraphic()->GetFrameWidth(),
		button->GetGraphic()->GetGraphic()->GetFrameHeight());
	button->SetPhysics(button->AddComponent<PhysicsBodyComponent>());
	button->GetPhysics()->Init(STATIC, 1, 1.0f, 0.0f, false, true);
	button->AddComponent<ButtonScript>();
	_vObject.push_back(button);

	button = new Button;
	button->Init(Vector2(2384, 2014));
	button->GetGraphic()->Init(true);
	button->SetName("Button3");
	button->GetGraphic()->SetPivot(CENTER);
	button->GetGraphic()->SetImgName("button");
	button->GetGraphic()->SetFPS(0.7f);
	button->GetTrans()->scale = Vector2(button->GetGraphic()->GetGraphic()->GetFrameWidth(),
		button->GetGraphic()->GetGraphic()->GetFrameHeight());
	button->SetPhysics(button->AddComponent<PhysicsBodyComponent>());
	button->GetPhysics()->Init(STATIC,1, 1.0f, 0.0f, false, true);
	button->AddComponent<ButtonScript>();
	_vObject.push_back(button);

	button = new Button;
	button->Init(Vector2(1821, 1444));
	button->GetGraphic()->Init(true);
	button->SetName("switch");
	button->GetGraphic()->SetPivot(CENTER);
	button->GetGraphic()->SetImgName("switch");
	button->GetGraphic()->SetFPS(0.7f);
	button->GetTrans()->scale = Vector2(button->GetGraphic()->GetGraphic()->GetFrameWidth(),
		button->GetGraphic()->GetGraphic()->GetFrameHeight());
	button->SetPhysics(button->AddComponent<PhysicsBodyComponent>());
	button->GetPhysics()->Init(STATIC, 1, 1.0f, 0.0f, false, true);
	button->AddComponent<ButtonScript>();
	_vObject.push_back(button);

	GRAPHICMANAGER->AddFrameImage("effect", L"firecracker.png", 19, 1);




}

void ObjectManager::Release()
{
	_vItem.clear();
	_vObject.clear();
	_vEffect.clear();
	SAFE_DELETE(_objPool);
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

	for (Object* i : _vObject)
	{
		if (i->GetTag() == "Button")
		{
			Button* button = (Button*)i;
			if (button->GetCollision())
			{
				if (KEYMANAGER->isOnceKeyDown('S'))
				{
					button->GetGraphic()->Stop();
					button->GetGraphic()->Start();
					button->SetIsActive(false);

					D2DEffect* effect = new D2DEffect;
					effect->Init(Vector2(button->GetTrans()->pos.x, button->GetTrans()->pos.y - 60));
					_vEffect.push_back(effect);
				}
			}
		}
		if (!i->GetIsActive()) i->GetComponent<PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(true);
	}

	for (int i = 0; i < _vEffect.size(); ++i)
	{
		_vEffect[i]->Update();
		if (_vEffect[i]->GetGraphic()->IsFrameEnd()) _vEffect.erase(_vEffect.begin() + i);
	}

	PlasmaOff("Button1", "Plasma1");
	PlasmaOff("Button1", "Plasma2");
}

void ObjectManager::Render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Render();
	}
	for (int i = 0; i < _vObject.size(); i++)
	{
		if(_vObject[i]->GetIsActive()|| _vObject[i]->GetTag()=="Button") _vObject[i]->Render();
	}

	for (D2DEffect* i : _vEffect) i->Render();
}

void ObjectManager::PlasmaOff(string btn, string pla)
{
	for (Object* i : _vObject)
	{
		if (i->GetName() == btn)
		{
			if (!i->GetIsActive())
			{
				for (Object* j : _vObject)
				{
					if (j->GetName() == pla)
					{
						j->SetIsActive(false);
					}
				}
			}
		}
	}
}
