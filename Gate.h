#pragma once
#include "Wall.h"
class Gate : public Wall
{
private:
	bool isOn;
	bool isDown;
	Vector2 up;
	Vector2 middle;
	Vector2 down;
public:
	Gate();
	~Gate();
	void Init(Vector2 pos, Vector2 scale,string key, bool pBody=false);
	bool GetIsOn() { return isOn; }
	void SetIsOn(bool on) { isOn = on; }
	bool GetIsDown() { return isDown; }
	void SetIsDown(bool down) { isDown = down; }
	void Up();
	void Down();
	void Originally();
	inline Vector2 GetUpPos() { return up; }
	inline Vector2 GetDownPos() { return down; }
	inline Vector2 GetMiddlePos() { return middle; }
	inline Vector2 GetPos() { return _trans->pos; }
};

