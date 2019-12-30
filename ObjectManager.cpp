#include "stdafx.h"
#include "ObjectManager.h"

void ObjectManager::Init()
{
	Item* item;
	item = new Tomato;
	item->Init(Vector2(100,100));
	_vItem.push_back(item);


}

void ObjectManager::Release()
{

}

void ObjectManager::Update()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Update();
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->Render();
	}
}
