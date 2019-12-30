#pragma once
#include "Wall.h"
class UIManager
{
private:
	Wall* test;
public:
	UIManager();
	~UIManager();
	void Init();
	void Release();
	void Update();
	void Render();
};

