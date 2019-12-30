#pragma once
#include "gameNode.h"
#include"UIManager.h"
class playGround : public gameNode
{
private:
	UIManager* _uiManager;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();

};

