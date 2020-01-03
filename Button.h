#pragma once
#include "Object.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

class Button : public Object
{
private:
	PhysicsBodyComponent* _physic;
	bool _isCollision;
protected:
	typedef Object super;
public:
	Button() {};
	~Button() {};

	virtual void Init();
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
	inline void SetPhysics(PhysicsBodyComponent* physics) { _physic = physics; }
	inline PhysicsBodyComponent* GetPhysics() { return _physic; }
	inline void SetCollision(bool on) { _isCollision = on; }
	inline bool GetCollision() { return _isCollision; }
};

