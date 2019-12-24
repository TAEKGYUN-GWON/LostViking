#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("�Ѿ�", 30, WINSIZEY);

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	_bullet->update();
	minionBulletFire();

	collision();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
}

void enemyManager::setMinion()
{
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("enemy", PointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);
		}
	}


}

void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		//�̴Ͼ� ���;ȿ� ����ִ� �̴Ͼ��� �Ѿ˹߻� ��ȣ��  true��
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();

			/*
				_bullet->bulletFire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + 5, -(PI / 2), 7.0f);
			*/
			_bullet->bulletFire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + 5, 
				getAngle((rc.left + rc.right) / 2,
					(rc.top + rc.bottom) / 2, 
					_ship->getShipImage()->getCenterX(),
					_ship->getShipImage()->getCenterY()),
				7.0f);

		
		}
	}

}

void enemyManager::removeMinion(int arrNum)
{
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT temp;
		RECT rc = RectMakeCenter(_ship->getShipImage()->getCenterX(),
			_ship->getShipImage()->getCenterY(),
			_ship->getShipImage()->getWidth(),
			_ship->getShipImage()->getHeight());

		if (IntersectRect(&temp, &_bullet->getVBullet()[i].rc, &rc))
		{
			//���ּ��� �Ѿ˿� �ǰݵǾ����� ü���� ��������
			_ship->hitDamage(10);
			_bullet->removeBullet(i);
			break;
		}


	}
	
}
