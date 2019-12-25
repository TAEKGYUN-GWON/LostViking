#pragma once
class Object;
enum Body_Type
{
	DYNAMIC,
	STATIC,
	KINEMATIC
};

class PhysicsBodyComponent
{
private:
	Object *_object;
	b2Body *_body;
	Body_Type _type;
public:
	PhysicsBodyComponent(Object* object);
	~PhysicsBodyComponent();
	void Init(Body_Type type);
	void SetBodyPosition();
	Vector2 GetBodyPosition();
	float GetBodyAngle() { return _body->GetAngle(); }
	inline b2Body* GetBody() { return _body; }
	Vector2 Convert(Vector2 origin);
};