#pragma once
#include "Character.h"

class Olaf :public Character
{
public:

	typedef Character super;

	Object* _upShield;
	Object* _leftShield;
	Object* _rightShield;

	Olaf();
	~Olaf();

	virtual void Init(float spawnX, float spawnY);
	virtual void Update();

	void SetShield();
	void ShieldMove();
	
	void ImageControl();
};

