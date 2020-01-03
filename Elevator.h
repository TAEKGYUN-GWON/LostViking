#pragma once
#include "Wall.h"
enum UpAndDown
{
	up,
	down
};
enum position
{
	top,
	middle,
	bottom
};
class Elevator :	public Wall
{
private:
	typedef Wall super;
	bool isOn;
	UpAndDown isUp;
	bool stop;
	position pos;
public:
	Elevator();
	~Elevator();
	virtual void Init();
	virtual void Update();
	inline void SetIsOn(bool on) { isOn = on; }
	inline void SetIsUp(UpAndDown up) { isUp = up; }
	inline bool GetIsOn() { return isOn; }
	inline UpAndDown GetIsUp() { return isUp; }
	inline void SetStop(bool stop) { this->stop = stop; }
	inline bool GetStop() { return stop; }
	inline position GetElevatorPos() { return pos; }
	inline void SetElevatorPos(position pos) { this->pos = pos; }
};

