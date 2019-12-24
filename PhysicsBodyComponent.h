#pragma once
class Object;
class PhysicsBodyComponent
{
private:
	Object *_object;
	b2Body *_body;

public:
	PhysicsBodyComponent(Object* object);
	~PhysicsBodyComponent();

	void AddDynamicBody(b2World *world);
	void AddStaticBody(b2World *world);
	void AddkinematicBody(b2World *world);
	void SetBodyPosition();
	Vector2 GetBodyPosition();
	float GetBodyAngle() { return _body->GetAngle(); }
	inline b2Body* GetBody() { return _body; }
	Vector2 Convert(Vector2 origin);
};