#pragma once
#include "Box2D/Box2D.h"
class Object;
class PhysicsManager : public b2ContactListener
{
private:
	b2World* _world;
	PhysicsManager();
public:
	static PhysicsManager* GetInstance();
	~PhysicsManager() {};
	b2World* GetWorld();
	void SetWorld(b2World *world);
	virtual void BeginContact(b2Contact* contact) override;
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
	virtual void EndContact(b2Contact* contact) override;
};