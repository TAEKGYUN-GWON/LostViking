#pragma once
#include "gameNode.h"
#include "ObjectManager.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "enemyManager.h"

class playGround : public gameNode
{
private:
	ObjectManager* _objMgr;
	UIManager* _uiMgr;
	PlayerManager* _playerMgr;
	EnemyManager* _enemyMgr;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();

};

