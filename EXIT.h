#pragma once
#include "Object.h"
#include "PhysicsBodyComponent.h"
class EXIT : public Object
{
private:
	int _vikingNum;
	PhysicsBodyComponent* _physics;
public:
	EXIT();
	~EXIT();
	void Init();
	inline void CountUp() { _vikingNum++; }
	inline void CountDown() { _vikingNum--; }
	bool GameEnd();
};

