#pragma once
#include "Character.h"
#include <vector>

class Olaf :public Character
{
public:

	typedef Character super;

	Object* _upShield;
	Object* _leftShield;
	Object* _rightShield;

	vector<Object*> _shields;

	Olaf();
	~Olaf();

	virtual void Init(float spawnX, float spawnY);
	virtual void Update();
	virtual void Render();

	void SetShield();
	void ShieldMove();
	void ShildChange();
	void ShieldState();

	void KeyControl();
	
	void ImageControl();
};

