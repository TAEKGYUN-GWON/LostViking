#pragma once
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _hill;		//언덕이미지
	image* _ball;		//공 이미지

	RECT _rc;			//공 렉트
	float _x, _y;		//공 중점 좌표

	int _probeY;		//Y축 탐사 변수

public:
	pixelCollision();
	~pixelCollision();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

