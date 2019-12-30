#pragma once
#include "Component.h"
enum BodyType
{
	DYNAMIC,
	STATIC,
	KINEMATIC
};

class TransformComponent;

class PhysicsBodyComponent : public Component
{
private:
	b2Body *_body;
	BodyType _type;
	TransformComponent* _trans;

public:
	PhysicsBodyComponent() { _name = "PhysicsBodyComponent"; }
	//바디 타입, 마찰력, 밀도(기본1), 반발력 (기본0), bullet인가, 뚫어도 되는 바디인가
	void Init(BodyType type, float32 friction, float32 density=1, float32 restitution = 0 , BOOL isBullet = FALSE, BOOL isSensor = FALSE);
	void SetBodyPosition();
	//바디 포지션 가져오기
	Vector2 GetBodyPosition();
	//사용 금지
	Vector2 GetBodyScale();
	//바디의 Rotate 가져오기
	float GetBodyAngle() { return _body->GetAngle(); }
	//바디 가져오기
	inline b2Body* GetBody() { return _body; }
	//바디의 GetWorldCenter 가져오기
	inline const b2Vec2 GetWorldCenter() { return _body->GetWorldCenter(); }
	//바디의 Active 껏다 키는 세팅 (잠들건지 말건지)
	inline void SetBodyActive(bool sleep) { _body->SetActive(sleep); }
	//바디에 힘 작용 시키기
	inline void ApplyForce(b2Vec2 force, bool wake = true) { _body->ApplyForce(force, _body->GetWorldCenter(), wake); }
	Vector2 Convert(Vector2 origin);
};