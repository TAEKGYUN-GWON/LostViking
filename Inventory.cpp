#include "stdafx.h"
#include "Inventory.h"
#include"Object.h"

Inventory::Inventory()
{
	_name = "Inventory";
}


Inventory::~Inventory()
{
}

void Inventory::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	if (to->GetTag() == "Item")
	{
		if(to->GetName()=="Tomato")
			InsertItem(TOMATO, "tomato");
		if (to->GetName() == "Bomb")
			InsertItem(BOMB, "bomba");
		if (to->GetName() == "Meat")
			InsertItem(MEAT, "meat");
	}
}

inline void Inventory::InsertItem(ITEM item, string key)
{
	if (_mInven.size() >= 4) return;

	tagItemInfo a;
		a.item = item;
		a.key = key;
	_mInven.insert(make_pair(_mInven.size(),a));
}

void Inventory::ActivationItem(ITEM item)
{
	for (mIter iter = _mInven.begin(); iter != _mInven.end();)
	{
		if (iter->second.item == item) _mInven.erase(iter);
		else iter++;
	}
}
