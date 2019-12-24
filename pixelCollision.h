#pragma once
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _hill;		//����̹���
	image* _ball;		//�� �̹���

	RECT _rc;			//�� ��Ʈ
	float _x, _y;		//�� ���� ��ǥ

	int _probeY;		//Y�� Ž�� ����

public:
	pixelCollision();
	~pixelCollision();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

