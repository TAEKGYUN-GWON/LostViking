#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;
	
	int _currentFrameX;		//�������̹��� 1���� ������ ���� �ٸ� �������� �����Ϸ���
	int _currentFrameY;

	int _count;				//������ ī��Ʈ��
	int _fireCount;			//�Ѿ� �߻��
	int _rndFireCount;		//�����ϰ� �� ����

public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();

	void move();
	void draw();

	bool bulletCountFire();		//�Ѿ� ���� ��ȣ�� �� �Լ�

	inline RECT getRect() { return _rc; }

};

