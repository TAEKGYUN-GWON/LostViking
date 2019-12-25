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
	//Vector2 타입 좌표 가져오기
	inline Vector2 GetPos() { return _pos; }
	//Vector2 타입 사이즈 가져오기
	inline Vector2 GetScale() { return _scale; }
	//디그리 값으로 회전값 가져오기
	inline float GetRotateDegree() { return _rotate * DEGREE; }
	//라디안 값으로 회전값 가져오기
	inline float GetRotateRadian() { return _rotate; }
	//x좌표 가져오기
	inline float GetX() { return _pos.GetX(); }
	//y좌표 가져오기
	inline float GetY() { return _pos.GetY(); }
	//width 가져오기
	inline float GetW() { return _scale.GetX(); }
	//height 가져오기
	inline float GetH() { return _scale.GetY(); }
	//Vector2 타입으로 좌표 설정하기
	inline void SetPos(Vector2 pos) { _pos = pos; }
	//float 타입으로 좌표 설정하기
	inline void SetPos(float x, float y) { _pos = Vector2(x, y); }
	//Vector2 타입으로 사이즈 설정하기
	inline void SetScale(Vector2 scale) { _scale = scale; }
	//float 타입으로 사이즈 설정하기
	inline void setScale(float w, float h) { _scale = Vector2(w, h); }
	//x좌표 세팅
	inline void SetX(float x) { _pos.SetX(x); }
	//y좌표 세팅
	inline void SetY(float y) { _pos.SetY(y); }
	//width 세팅
	inline void SetW(float w) { _scale.SetX(w); }
	//height 세팅
	inline void SetH(float h) { _scale.SetY(h); }
	//라디안값으로 회전값 세팅
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }
	//디그리 값으로 회전값 세팅
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * RADIAN; }
	//렉트 가져오기
	inline RECT* getRect() { return &_rc; }
};

