#pragma once
#include "Object.h"
class yest : public Object
{
	typedef Object super;
public:
	yest();
	~yest();
	virtual void Init()override;
	virtual void Update()override;
	virtual void Release()override;
	virtual void test();
};

