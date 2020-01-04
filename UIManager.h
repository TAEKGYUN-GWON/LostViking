#pragma once
#include "Wall.h"
#include"Elevator.h"
#include"PlayerManager.h"
#include"EXIT.h"
#include "Button.h"
class UIManager
{
private:
	int curFrameX4;
	int curFrameX6;
	int count;
	vector<Wall*> _vWalls;
	Elevator *_elevator;
	Vector2 camera;
	PlayerManager* _pMgr;
	EXIT* _exit;
	Button* _button;

public:
	UIManager();
	~UIManager();
	void Init();
	void Release();
	void Update();
	void Render();
	void UiRender();
	void BehindRender();
	void Frame();
	void DrawTwinkle();
	void ElevatorMove();
	Elevator* GetElevator() { return _elevator; }
	void SetPlayerManagerLink(PlayerManager* pMgr) { _pMgr = pMgr; }
	void GateMove();
	bool GetGameEnd() { return _exit->GameEnd(); }
};

