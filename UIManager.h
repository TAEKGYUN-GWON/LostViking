#pragma once
#include "Wall.h"
class UIManager
{
private:
	int curFrameX4;
	int curFrameX6;
	int count;
	vector<Wall*> _vWalls;
	Object *p;
	Vector2 camera;
public:
	UIManager();
	~UIManager();
	void Init();
	void Release();
	void Update();
	void Render();
	void Frame();
	void DrawTwinkle();
	void CameraMove();
	void PMove();
};

