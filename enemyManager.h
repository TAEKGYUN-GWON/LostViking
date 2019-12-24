#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

//������� ���ӹ����� ���� Ŭ���� ���漱��
class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	bullet* _bullet;
	spaceShip* _ship;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�̴Ͼ� ���� �Լ�
	void setMinion();

	//�̴Ͼ� �Ѿ� �߻� ��� �Լ�
	void minionBulletFire();

	void removeMinion(int arrNum);

	void collision();

	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; }

	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getViMinion() { return _viMinion; }
};

