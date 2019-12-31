#pragma once
#include "Wall.h"
class UIManager
{
private:
	vector<Wall*> _vWalls;
	Object *p;
public:
	UIManager();
	~UIManager();
	void Init();
	void Release();
	void Update();
	void Render();
};

