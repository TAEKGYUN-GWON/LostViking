#pragma once
#include "Component.h"
class TransformComponent : public Component
{
private:
	
	float _rotate;
	RECT _rc;

public:
	typedef Component super;
	Vector2 pos;
	Vector2 scale;
	TransformComponent() { _name = "TransformComponent"; }
	virtual void Init() override;
	virtual void Update() override;
	//Vector2 Ÿ�� ��ǥ ��������
	inline Vector2 GetPos() { return pos; }
	//Vector2 Ÿ�� ������ ��������
	inline Vector2 GetScale() { return scale; }
	//��׸� ������ ȸ���� ��������
	inline float GetRotateDegree() { return _rotate * DEGREE; }
	//���� ������ ȸ���� ��������
	inline float GetRotateRadian() { return _rotate; }

	//Vector2 Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(Vector2 pos) { this->pos = pos; }
	//float Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(float x, float y) { pos = Vector2(x, y); }
	//Vector2 Ÿ������ ������ �����ϱ�
	inline void SetScale(Vector2 scale) { this->scale = scale; }
	//float Ÿ������ ������ �����ϱ�
	inline void SetScale(float w, float h) { scale = Vector2(w, h); }

	//���Ȱ����� ȸ���� ����
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }
	//��׸� ������ ȸ���� ����
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * DEGREE; }
	inline RECT* GetRect() { return &_rc; }
	inline void SetRect(RECT rc) { _rc = rc; }
	void SetRect();
};

