#pragma once
#include "Object.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"
#include <vector>

class Item : public Object
{
private:
	PhysicsBodyComponent* _physic;
	bool _isCollision;
protected: 
	typedef Object super;

public:
	Item() {};
	~Item() {};

	virtual void Init() override;
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
	inline void SetPhysics(PhysicsBodyComponent* physics) { _physic = physics; }
	inline PhysicsBodyComponent* GetPhysics() { return _physic; }
	inline void SetColliosion(bool on) { _isCollision = on; }
	inline bool GetColliosion() { return _isCollision; }
};

