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

	Vector2 _pos;
	Vector2 _pos2;

	bool _isPlayer1;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();

};

