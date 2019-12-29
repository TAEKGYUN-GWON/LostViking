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
	//������, �е�(�⺻1), �ݹ߷� (�⺻0), bullet�ΰ�, �վ �Ǵ� �ٵ��ΰ�
	void Init(BodyType type, float32 friction, float32 density=1, float32 restitution = 0 , BOOL isBullet = FALSE, BOOL isSensor = FALSE);
	void SetBodyPosition();
	Vector2 GetBodyPosition();
	Vector2 GetBodyScale();
	float GetBodyAngle() { return _body->GetAngle(); }
	inline b2Body* GetBody() { return _body; }
	inline const b2Vec2 GetWorldCenter() { return _body->GetWorldCenter(); }
	inline void SetBodyActive(bool sleep) { _body->SetActive(sleep); }
	Vector2 Convert(Vector2 origin);
};