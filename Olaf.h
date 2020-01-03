#pragma once
#include "Character.h"
class Olaf :public Character
{
public:
	Olaf();
	~Olaf();

	virtual void Init();
	virtual void Update();
	
	void ImageControl();
};

