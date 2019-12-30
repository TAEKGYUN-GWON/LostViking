#pragma once
#include "Tomato.h"
#include <vector>

class ObjectManager 
{
private:
	vector<Item*>			_vItem;
	vector<Item*>::iterator	_viItem;

public:

	void Init();
	void Release();
	void Update();
	void Render();
};

