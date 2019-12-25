#pragma once
class Object;

class TransformComponent
{
private:
	RECT _rc;
	Object *_object;
	Vector2 _pos;
	Vector2 _scale;
	float _rotate;
public:
	TransformComponent(Object* object);
	~TransformComponent();
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
	inline float GetX() { return _pos.GetX(); }
	//y��ǥ ��������
	inline float GetY() { return _pos.GetY(); }
	//width ��������
	inline float GetW() { return _scale.GetX(); }
	//height ��������
	inline float GetH() { return _scale.GetY(); }
	//Vector2 Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(Vector2 pos) { _pos = pos; }
	//float Ÿ������ ��ǥ �����ϱ�
	inline void SetPos(float x, float y) { _pos = Vector2(x, y); }
	//Vector2 Ÿ������ ������ �����ϱ�
	inline void SetScale(Vector2 scale) { _scale = scale; }
	//float Ÿ������ ������ �����ϱ�
	inline void setScale(float w, float h) { _scale = Vector2(w, h); }
	//x��ǥ ����
	inline void SetX(float x) { _pos.SetX(x); }
	//y��ǥ ����
	inline void SetY(float y) { _pos.SetY(y); }
	//width ����
	inline void SetW(float w) { _scale.SetX(w); }
	//height ����
	inline void SetH(float h) { _scale.SetY(h); }
	//���Ȱ����� ȸ���� ����
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }
	//��׸� ������ ȸ���� ����
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * RADIAN; }
	//��Ʈ ��������
	inline RECT* getRect() { return &_rc; }
};

