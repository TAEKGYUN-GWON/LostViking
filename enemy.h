#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;
	
	int _currentFrameX;		//프레임이미지 1개를 가지가 각각 다른 프레임을 유지하려고
	int _currentFrameY;

	int _count;				//프레임 카운트용
	int _fireCount;			//총알 발사용
	int _rndFireCount;		//랜덤하게 쏠 변수

public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();

	void move();
	void draw();

	bool bulletCountFire();		//총알 쏘라고 신호를 줄 함수

	inline RECT getRect() { return _rc; }

};

