#pragma once
#include "gameNode.h"
#include "Player.h"
//BOX2D �����ڵ� 
class playGround : public gameNode
{
private:
	Player* _player;
	//WORLD
	b2World* _world;
	//BODY
	b2Body* _groundBody;
	b2Body* _dynamicBody;
	//�׽�Ʈ�� ����
	bool _tested;

	int _curFrameX;
	int _curFrameY;
	int _count;

	Graphic* _img;
	Graphic* _img2;
	Graphic* _img3;

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

