#pragma once
#include "gameNode.h"
#include "ObjectManager.h"
#include "UIManager.h"
#include "enemy.h"
#include "EnemyManager.h"

class playGround : public gameNode
{
private:
	ObjectManager* _objMgr;
	UIManager* _uiMgr;
	//Enemy* _enemy;
	EnemyManager* _enemyMgr;

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

