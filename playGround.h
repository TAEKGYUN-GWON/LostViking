#pragma once
#include "gameNode.h"
#include "yest.h"
//BOX2D 예제코드 
class playGround : public gameNode
{
private:
	//WORLD
	b2World* _world;
	//BODY
	b2Body* _groundBody;
	b2Body* _dynamicBody;
	//테스트용 변수
	bool _tested;

	int _curFrameX;
	int _curFrameY;
	int _count;
	Object* t;
	Object* a;
	Graphic* _img;
	Graphic* _img2;
	Graphic* _img3;
	yest* ys;
	float _x;
	float _y;
	float _angle;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();
	void FrameAnimation();

};

