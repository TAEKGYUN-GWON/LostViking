#pragma once
#include "Object.h"
#include <vector>

class Item : public Object
{
private:

protected: 
	typedef Object super;

public:
	Item() {};
	~Item() {};

	virtual void Init() override;
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
	
};

