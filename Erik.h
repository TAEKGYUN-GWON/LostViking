#pragma once
#include "Character.h"
class Erik :public Character
{
private:
	float _jumpPower;
	float _gravity;

protected:
	typedef Character super;

public:
	Erik();
	~Erik();

	virtual void Init(float spawnX, float spawnY) override;
	virtual void Update() override;
	virtual void Render();
	void KeyControl1();

	void ImageControl();
};
