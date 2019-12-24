#pragma once
#include "singletonBase.h"
#include <time.h>

class randomFunction : public singletonBase<randomFunction>
{
public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction()
	{

	}

	//===============  ������ ���� =======================

	//          0 ~ �Ű������� ���� ���� - 1 ��ŭ ���� ����
	inline int getInt(int num) { return rand() % num; }

	//        ������ ���� ���� �������� ������ ���� �̴� �Լ�
	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum) + fromNum;
	}

	//================== �Ǽ��� ���� ============================
	float getFloat() { return (float)rand() / (float)RAND_MAX; }
	float getFloat(float num) { return ((float)rand() / (float)RAND_MAX) * num; }

	inline float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toNum - fromNum) + fromNum);
	}



};

