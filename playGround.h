#pragma once
#include "gameNode.h"
#include "ObjectManager.h"
#include "UIManager.h"
#include "PlayerManager.h"
class playGround : public gameNode
{
private:
	ObjectManager* _objMgr;
	UIManager* _uiMgr;
	PlayerManager* _playerMgr;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();

};

