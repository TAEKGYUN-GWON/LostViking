#pragma once
#include "gameNode.h"
#include "Character.h"

class playGround : public gameNode
{
private:

	Character* c;
	Object* flore;
	Object* _ladder;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();

};

