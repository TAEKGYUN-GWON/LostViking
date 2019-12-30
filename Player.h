#pragma once
#include"Object.h"

class Player :public Object
{
private:

protected:
	typedef Object super;

public:

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

