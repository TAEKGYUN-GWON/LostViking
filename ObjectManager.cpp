#include "stdafx.h"
#include "ObjectManager.h"

void ObjectManager::Init()
{
	_isTest = true;

	Item* item;
	item = new Tomato;
	item->Init(Vector2(100,100));
	_vItem.push_back(item);

	item = new Meat;
	item->Init(Vector2(200, 200));
	_vItem.push_back(item);

	item = new Bomb;
	item->Init(Vector2(300, 300));
	_vItem.push_back(item);

	Plasma* plasma;
	plasma = new Plasma;
	plasma->Init(Vector2(400, 400));
	_vObject.push_back(plasma);

	plasma = new Plasma;
	plasma->Init(Vector2(400, 600));
	_vObject.push_back(plasma);


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
