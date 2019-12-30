#pragma once
#include "Player.h"

class Eric : public Player
{
private:

protected:
	typedef Player super;

public:

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

