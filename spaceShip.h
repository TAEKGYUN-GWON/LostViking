#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

#pragma warning(disable:4996)

class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	littleBoy* _boy;

	enemyManager* _em;

	progressBar* _hpBar;

	//현재 체력과 최대체력
	float _currentHP, _maxHP;

	int _alphaValue;

public:
	spaceShip();
	~spaceShip();
	//함수 모두 드래그 후에 ALT + ENTER C C ENTER
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision();

	void hitDamage(float damage);

	image* getShipImage() { return _ship; }

	littleBoy* getBoy() { return _boy; }

	void setMemoryAddressLink(enemyManager* em) { _em = em; }
};

