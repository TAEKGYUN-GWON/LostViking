#pragma once
#include "Object.h"
class PhysicsBodyComponent;
class Wall : public Object
{
private:
	PhysicsBodyComponent* physics;
protected:
	typedef Object super;
public:
	Wall();
	~Wall();
	virtual void Init();
};

