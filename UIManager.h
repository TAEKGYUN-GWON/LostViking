#pragma once
#include "Wall.h"
#include"Elevator.h"
#include"PlayerManager.h"
class UIManager
{
private:
	int curFrameX4;
	int curFrameX6;
	int count;
	vector<Wall*> _vWalls;
	Object *p;
	Elevator *_elevator;
	Vector2 camera;
	PlayerManager* _pMgr;
public:
	UIManager();
	~UIManager();
	void Init();
	void Release();
	void Update();
	void Render();
	void UiRender();
	void Frame();
	void DrawTwinkle();
	void CameraMove();
	void PMove();
	void ElevatorMove();
	Elevator* GetElevator() { return _elevator; }
	void SetPlayerManagerLink(PlayerManager* pMgr) { _pMgr = pMgr; }
};

