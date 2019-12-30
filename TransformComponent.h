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
	//Vector2 타입 좌표 가져오기
	inline Vector2 GetPos() { return pos; }
	//Vector2 타입 사이즈 가져오기
	inline Vector2 GetScale() { return scale; }
	//디그리 값으로 회전값 가져오기
	inline float GetRotateDegree() { return _rotate * DEGREE; }
	//라디안 값으로 회전값 가져오기
	inline float GetRotateRadian() { return _rotate; }

	//Vector2 타입으로 좌표 설정하기
	inline void SetPos(Vector2 pos) { this->pos = pos; }
	//float 타입으로 좌표 설정하기
	inline void SetPos(float x, float y) { pos = Vector2(x, y); }
	//Vector2 타입으로 사이즈 설정하기
	inline void SetScale(Vector2 scale) { this->scale = scale; }
	//float 타입으로 사이즈 설정하기
	inline void SetScale(float w, float h) { scale = Vector2(w, h); }

	//라디안값으로 회전값 세팅
	inline void SetRotateToRadian(float rotate) { _rotate = rotate; }
	//디그리 값으로 회전값 세팅
	inline void SetRotateToDegree(float rotate) { _rotate = rotate * DEGREE; }
	inline RECT* GetRect() { return &_rc; }
	inline void SetRect(RECT rc) { _rc = rc; }
	void SetRect();
};

