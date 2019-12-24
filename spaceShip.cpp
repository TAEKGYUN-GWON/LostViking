#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}

HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("플레이어", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2);
	_ship->setY(WINSIZEY / 2 + 200);

	_missile = new missile;
	_missile->init(30, 400);

	_boy = new littleBoy;
	_boy->init(30, 800);

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 10, _ship->getWidth(), 10);
	_currentHP = _maxHP = 100;

	_alphaValue = 255;

	return S_OK;
}

void spaceShip::release()
{
}

void spaceShip::update()
{
	//왼쪽 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0)
	{
		_ship->setX(_ship->getX() - 5);
	}

	//오른쪽 이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth() < WINSIZEX)
	{
		_ship->setX(_ship->getX() + 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0)
	{
		_ship->setY(_ship->getY() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY)
	{
		_ship->setY(_ship->getY() + 5);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getCenterX(), _ship->getY() - 20);
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_boy->fire(_ship->getCenterX(), _ship->getY() - 10);
	}

	_missile->update();
	_boy->update();

	//76, 77, 78번째 줄까지해서 프로그레스 바의 위치를 우주선에 맞춰준다
	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 20);
	_hpBar->update();

	_hpBar->setGauge(_currentHP, _maxHP);

	collision();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("세이브테스트.txt", vStr);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("세이브테스트.txt");

		_currentHP = (atoi(vStr[0].c_str()));
		_maxHP = (atoi(vStr[1].c_str()));
		_ship->setX(atoi(vStr[2].c_str()));
		_ship->setY(atoi(vStr[3].c_str()));
	}


	if (_alphaValue <= 0) _alphaValue = 255;
	_alphaValue--;


}

void spaceShip::render()
{
	//_ship->render(getMemDC(), _ship->getX(), _ship->getY());
	_ship->alphaRender(getMemDC(), _ship->getX(), _ship->getY(), _alphaValue);
	_missile->render();
	_boy->render();
	_hpBar->render();
}

void spaceShip::collision()
{
	for (int i = 0; i < _em->getVMinion().size(); i++)
	{
		for (int j = 0; j < _boy->getVBoy().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_boy->getVBoy()[j].rc, &_em->getVMinion()[i]->getRect()))
			{
				_em->removeMinion(i);
				_boy->removeBoy(j);
				break;
			}
		}
	}

}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}
