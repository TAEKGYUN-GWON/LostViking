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
	//Vector2 타입 좌표 가져오기
	inline Vector2 GetPos() { return _pos; }
	//Vector2 타입 사이즈 가져오기
	inline Vector2 GetScale() { return _scale; }
	//디그리 값으로 회전값 가져오기
	inline float GetRotateDegree() { return _rotate * DEGREE; }
	//라디안 값으로 회전값 가져오기
	inline float GetRotateRadian() { return _rotate; }
	//x좌표 가져오기
	inline float GetX() { return _pos.x; }
	//y좌표 가져오기
	inline float GetY() { return _pos.y; }
	//width 가져오기
	inline float GetW() { return _scale.x; }
	//height 가져오기
	inline float GetH() { return _scale.y; }
	//Vector2 타입으로 좌표 설정하기
	inline void SetPos(Vector2 pos) { _pos = pos; }
	//float 타입으로 좌표 설정하기
	inline void SetPos(float x, float y) { _pos = Vector2(x, y); }
	//Vector2 타입으로 사이즈 설정하기
	inline void SetScale(Vector2 scale) { _scale = scale; }
	//float 타입으로 사이즈 설정하기
	inline void SetScale(float w, float h) { _scale = Vector2(w, h); }
	//x좌표 세팅
	inline void SetX(float x) { _pos.x=x; }
	//y좌표 세팅
	inline void SetY(float y) { _pos.y=y; }
	//width 세팅
	inline void SetW(float w) { _scale.x=w; }
	//height 세팅
	inline void SetH(float h) { _scale.y=h; }
	//라디안값으로 회전값 세팅
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }
	//디그리 값으로 회전값 세팅
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * RADIAN; }
	inline RECT* GetRect() { return &_rc; }
	inline void SetRect(RECT rc) { _rc = rc; }
	void SetRect();
};

