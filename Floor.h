#pragma once
#include "Wall.h"
class Floor :	public Wall
{
public:
	Floor();
	~Floor();
	virtual void Init();
};

