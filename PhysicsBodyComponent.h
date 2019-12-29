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
	//만약 Bullet이라면 두 번째 인자값을 true로 해주세요 만약 박스를 밀어내지 않고 뚫고 싶다면 세 번째 인자값을 true로 넣어주세요
	void Init(BodyType type, BOOL isBullet = FALSE, BOOL isSensor = FALSE);
	void SetBodyPosition();
	Vector2 GetBodyPosition();
	Vector2 GetBodyScale();
	float GetBodyAngle() { return _body->GetAngle(); }
	inline b2Body* GetBody() { return _body; }
	Vector2 Convert(Vector2 origin);
};