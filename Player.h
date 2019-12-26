#pragma once
#include "Object.h"
class Player :public Object
{
public:
	typedef Object super;
	Player();
	~Player();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
};

