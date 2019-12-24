#pragma once
//==============================
// ## 19.10.30 ## ��ũ�� ##
//==============================

inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };

	return pt;
}

inline POINTFLOAT PointFloatMake(float x, float y)
{
	POINTFLOAT pt = { x, y };

	return pt;
}

//          ���߱�  �ѷ���DC, ������ǥX, ������ǥY, ����ǥX, ����ǥY
inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

//================= ��Ʈ ���� �Ծ� ===================
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;
}

inline RECT RectMakeCenter(int centerX, int centerY, int width, int height)
{
	RECT rc = { centerX - (width / 2), centerY - (height / 2), centerX + (width / 2), centerY + (height / 2) };

	return rc;
}


//============== �� �� �� =====================
//       Left, Top�� ����(�׷���DC, Left, Top, ����ũ��, ����ũ��)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}
//          ������ǥ ���� (�׷���DC, ����X, ����Y, ����ũ��, ����ũ��)
inline void RectangleMakeCenter(HDC hdc, int centerX, int centerY, int width, int height)
{
	Rectangle(hdc, centerX - (width / 2), centerY - (height / 2), centerX + (width / 2), centerY + (height / 2));
}

inline void Rectangle(HDC hdc, RECT& rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

//============== �� ===================
//			Left, Top�� ����(�׷���DC, Left, Top, ����ũ��, ����ũ��)
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}
//          ������ǥ ���� (�׷���DC, ����X, ����Y, ����ũ��, ����ũ��)
inline void EllipseMakeCenter(HDC hdc, int centerX, int centerY, int width, int height)
{
	Ellipse(hdc, centerX - (width / 2), centerY - (height / 2), centerX + (width / 2), centerY + (height / 2));
}

inline void Ellipse(HDC hdc, RECT& rc)
{
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}
