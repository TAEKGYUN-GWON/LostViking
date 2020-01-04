#pragma once
#include "Component.h"

enum STATE
{
	IDLE,
	MOVE,
	JUMP,
	ISLADDER,
	DEATH,
	SPECIAL1,
	SPECIAL2
};
class State : public Component
{
public:
	STATE state;
	//0 ���� 1 ������
	int direction;
	State();
	~State();
};

