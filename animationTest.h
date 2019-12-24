#pragma once
#include "gameNode.h"
#include "effect.h"

class animationTest : public gameNode
{
private:
	image* _camel;

	animation* _ani1;	//����Ʈ �ִϸ��̼� �����
	animation* _ani2;	//�迭 �ִϸ��̼� �����
	animation* _ani3;	//���� �ִϸ��̼� �����

	effect* _effect;
public:
	animationTest();
	~animationTest();

	HRESULT init();
	void release();
	void update();
	void render();
};

