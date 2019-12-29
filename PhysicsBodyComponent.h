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
	void Init(BodyType type);
	void SetBodyPosition();
	Vector2 GetBodyPosition();
	Vector2 GetBodyScale();
	float GetBodyAngle() { return _body->GetAngle(); }
	inline b2Body* GetBody() { return _body; }
	Vector2 Convert(Vector2 origin);
};