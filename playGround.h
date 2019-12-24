#pragma once
#include "gameNode.h"
//BOX2D �����ڵ� 
class playGround : public gameNode
{
private:

	//WORLD
	b2World* _world;
	//BODY
	b2Body* _groundBody;
	b2Body* _dynamicBody;
	//�׽�Ʈ�� ����
	bool _tested;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render();	//�׸��� ���� �Լ�

};

