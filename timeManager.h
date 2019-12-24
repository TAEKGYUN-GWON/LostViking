#pragma once
#include "singletonBase.h"
#include "timer.h"

class timeManager : public singletonBase <timeManager>
{
private:
	timer* _timer;

public:
	timeManager();
	~timeManager();

	HRESULT init();
	void release();
	void update(float lockFPS = 0.0f);
	void render(HDC hdc);

	//Delta타임
	inline float getElapsedTime() const { return _timer->getElapsedTime(); }

	//World타임
	inline float getWorldTime() const { return _timer->getWorldTime(); }

};

