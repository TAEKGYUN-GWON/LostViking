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
	inline Vector2 GetPos() { return _pos; }
	inline Vector2 GetScale() { return _scale; }
	inline float GetRotateDegree() { return _rotate * DEGREE; }
	inline float GetRotateRadian() { return _rotate; }
	inline float GetX() { return _pos.GetX(); }
	inline float GetY() { return _pos.GetY(); }
	inline float GetW() { return _scale.GetX(); }
	inline float GetH() { return _scale.GetY(); }
	inline void SetPos(Vector2 pos) { _pos = pos; }
	inline void SetPos(float x, float y) { _pos = Vector2(x, y); }
	inline void SetScale(Vector2 scale) { _scale = scale; }
	inline void setScale(float w, float h) { _scale = Vector2(w, h); }
	inline void SetX(float x) { _pos.SetX(x); }
	inline void SetY(float y) { _pos.SetY(y); }
	inline void SetW(float w) { _scale.SetX(w); }
	inline void SetH(float h) { _scale.SetY(h); }
	inline void SetRotate(float rotate) { _rotate = rotate; }
	inline RECT* getRect() { return &_rc; }
};

