#pragma once
#include "gameNode.h"
#include "Enemy.h"

class playGround : public gameNode
{
private:
	Object* a;
	Object* leftWall;
	Object* rightWall;



	Enemy* _enemy;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();

};

