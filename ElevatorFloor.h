#pragma once
#include "Wall.h"
class ElevatorFloor :	public Wall
{
	typedef Wall super;
public:
	ElevatorFloor();
	~ElevatorFloor();

	virtual void Init();
	virtual void Update();
};

