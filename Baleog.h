#pragma once
#include "Character.h"
class Baleog :public Character
{
public:
	Baleog();
	~Baleog();

	virtual void Init();
	virtual void Update();

	void ImageControl();
};