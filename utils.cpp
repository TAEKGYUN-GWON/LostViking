#include "stdafx.h"
#include "utils.h"



namespace SEVENTEEN_UTIL
{
	//�Ÿ�(����) �˾ƿ��� �Լ�
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	//�� ���� ���̰��� �˾ƿ��� �Լ�
	float getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		//���� ��ũ�ڽ����� ���ؿ� �ϸ� �� �ּ��� Ǯ�� ������
		/*
		float distance = sqrtf(x * x + y * y);

		float angle = acosf(x / distance);

		if (y2 > y1)
		{
			angle = PI2 - angle;

			if (angle >= PI2) angle -= PI2;
		}
		*/


		//��ũź��Ʈ�� ���ϴ� �״뿩 �̰� ������
		float angle = -atan2f(y, x);


		return angle;

	}
}