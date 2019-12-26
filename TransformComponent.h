#pragma once
#include "Component.h"
class TransformComponent : public Component
{
private:
	
	Vector2 _pos;
	Vector2 _scale;
	float _rotate;
	RECT _rc;

public:
	typedef Component super;
	TransformComponent() { _name = "TransformComponent"; }
	void Init();
	void Update();
	//Vector2 Ÿ�� ��ǥ ��������
	inline Vector2 GetPos() { return _pos; }
	//Vector2 Ÿ�� ������ ��������
	inline Vector2 GetScale() { return _scale; }
	//��׸� ������ ȸ���� ��������
	inline float GetRotateDegree() { return _rotate * DEGREE; }
	//���� ������ ȸ���� ��������
	inline float GetRotateRadian() { return _rotate; }
	//x��ǥ ��������
	inline float GetX() { return _pos.x; }
	//y��ǥ ��������
	inline float GetY() { return _pos.y; }
	//width ��������
	inline float GetW() { return _scale.x; }
	//height ��������
	inline float GetH() { return _scale.y; }
	//Vector2 Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(Vector2 pos) { _pos = pos; }
	//float Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(float x, float y) { _pos = Vector2(x, y); }
	//Vector2 Ÿ������ ������ �����ϱ�
	inline void SetScale(Vector2 scale) { _scale = scale; }
	//float Ÿ������ ������ �����ϱ�
	inline void SetScale(float w, float h) { _scale = Vector2(w, h); }
	//x��ǥ ����
	inline void SetX(float x) { _pos.x=x; }
	//y��ǥ ����
	inline void SetY(float y) { _pos.y=y; }
	//width ����
	inline void SetW(float w) { _scale.x=w; }
	//height ����
	inline void SetH(float h) { _scale.y=h; }
	//���Ȱ����� ȸ���� ����
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }
	//��׸� ������ ȸ���� ����
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * RADIAN; }
	inline RECT* GetRect() { return &_rc; }
	inline void SetRect(RECT rc) { _rc = rc; }
	void SetRect();
};

