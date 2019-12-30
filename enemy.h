#pragma once
#include "Object.h"
class Enemy :	public Object
{
private:


protected:
	typedef Object super;

public:
	Enemy() {};
	~Enemy() {};

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void Move();
	void Shoot();
};

