#pragma once
#include "gameNode.h"
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
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render();	//그리기 전용 함수

};

