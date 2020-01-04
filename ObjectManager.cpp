#include "stdafx.h"
#include "ObjectManager.h"
#include "GraphicComponent.h"
#include "ButtonScript.h"
#include "ItemScript.h"
#include "BombScript.h"

void ObjectManager::Init()
{
	Item* item;
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■토마토■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	item = new Tomato;
	item->Init(Vector2(420,530));
	item->AddComponent<ItemScript>();
	_vItem.push_back(item);

	item = new Tomato;
	item->Init(Vector2(783, 192));
	item->AddComponent<ItemScript>();
	_vItem.push_back(item);
	
	item = new Tomato;
	item->Init(Vector2(1486, 2050));
	item->AddComponent<ItemScript>();
	_vItem.push_back(item);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■고기■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	item = new Meat;
	item->Init(Vector2(2600, 850));
	item->AddComponent<ItemScript>();
	_vItem.push_back(item);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■폭탄■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  
	item = new Bomb;
	item->Init(Vector2(2080, 208));
	item->AddComponent<BombScript>();
	item->AddComponent<ItemScript>();
	_vItem.push_back(item);

	item = new Bomb;
	item->Init(Vector2(2080, 160));
	item->AddComponent<BombScript>();
	item->AddComponent<ItemScript>();
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
	tower->SetName("tower1");
	_vObject.push_back(tower);

	tower = new RedgunTower;
	tower->Init(Vector2(80, 1555),1);
	tower->SetName("tower2");
	_vObject.push_back(tower);

	tower = new RedgunTower;
	tower->Init(Vector2(950, 2025),0);
	tower->SetName("tower3");
	_vObject.push_back(tower);

	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■컴퓨터■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	Computer* com;
	com = new Computer;
	com->Init(Vector2(1870, 2051));
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


	GRAPHICMANAGER->AddFrameImage("effect", L"firecracker.png", 19, 1);

	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■총알■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

	GRAPHICMANAGER->AddImage("cannon_bullet", L"cannon_bullet.png");

	Bullet* bullet = new Bullet;
	bullet->Init("cannon_bullet", "Bullet", "cannon_bullet");

	_objPool = new ObjectPool;
	_objPool->Init<Bullet>(50, *bullet);

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
	for (int i = 0; i < _vItem.size(); i++)
	{
		if (!_vItem[i]->GetIsActive()) _vItem[i]->SetIsActive(false);
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
	PlasmaOff("Button2", "Plasma3");
	PlasmaOff("Button3", "Plasma6");
	PlasmaOff("Computer", "Plasma4");
	PlasmaOff("Computer", "Plasma5");
	PlasmaOff("Computer", "Plasma7");


	for (Object* a : _objPool->GetActivePool()) a->Update();

	Fire();


	for (Item* i : _vItem)
	{
		if (i->GetTag() == "Item")
		{
			Item* item = (Item*)i;
			if (item->GetColliosion())
			{
				item->SetIsActive(false);
			}
		}
		if (!i->GetIsActive()) i->GetComponent<PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(true);
	}

	for (Item* i : _vItem)
	{
		if (i->GetName() == "Bomb")
		{
			Bomb* item = (Bomb*)i;
			if (item->GetColliosion())
			{
				item->SetBomb(true);
			}
		}
	}



}

void ObjectManager::Render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		if(_vItem[i]->GetIsActive()) _vItem[i]->Render();
	}
	for (int i = 0; i < _vObject.size(); i++)
	{
		if(_vObject[i]->GetIsActive()|| _vObject[i]->GetTag()=="Button") _vObject[i]->Render();
	}

	for (D2DEffect* i : _vEffect) i->Render();

	for (Object* a : _objPool->GetActivePool()) a->Render();

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

void ObjectManager::Fire()
{
	for (Object* i : _vObject)
	{
		if (i->GetTag() == "RedgunTower")
		{
			RedgunTower* tower = (RedgunTower*)i;

			if (tower->GetName() == "tower1" || tower->GetName() == "tower2")
			{
				if (tower->IsBulletFire())
				{
					((Bullet*)_objPool->GetPoolObject())->Fire(Vector2(tower->GetTrans()->pos.x + 70, tower->GetTrans()->pos.y - 10), 0, 200);
					_objPool->InssertActiveObject();
				}
			}
			else if (tower->GetName() == "tower3")
			{
				if (tower->IsBulletFire())
				{
					((Bullet*)_objPool->GetPoolObject())->Fire(Vector2(tower->GetTrans()->pos.x - 70, tower->GetTrans()->pos.y - 10), PI, 200);
					_objPool->InssertActiveObject();
				}
			}
		}
	}

	for (int i = 0; i < _objPool->GetActivePoolSize(); ++i)
	{
		if (!_objPool->GetActivePool()[i]->GetIsActive())
		{
			_objPool->GetActivePool()[i]->GetComponent<PhysicsBodyComponent>()->GetBody()->SetActive(false);
			_objPool->InssertPool(i);
		}
	}
}
