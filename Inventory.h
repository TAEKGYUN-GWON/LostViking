#pragma once
#include "Collider.h"
#include <map>
enum ITEM
{
	TOMATO,
	MEAT,
	BOMB
};

struct tagItemInfo
{
	ITEM item;
	string key;
};

class Inventory : public Collider
{
	typedef map<int, tagItemInfo>::iterator mIter;
	map<int, tagItemInfo> _mInven;
public:
	Inventory();
	~Inventory();
	virtual void CollisionBegin(void* obj);
	void InsertItem(ITEM item, string key);
	void ActivationItem(ITEM item);
	inline map<int, tagItemInfo> GetInven() { return _mInven; }
};

