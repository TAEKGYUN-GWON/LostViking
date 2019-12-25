#include "stdafx.h"
#include "PhysicsManager.h"


PhysicsManager::PhysicsManager()
{
}

PhysicsManager * PhysicsManager::GetInstance()
{
	static PhysicsManager* instance = new PhysicsManager();
	return instance;
}

b2World * PhysicsManager::GetWorld()
{
	return _world;
}

void PhysicsManager::SetWorld(b2World * world)
{
	_world = world;
}

void PhysicsManager::BeginContact(b2Contact * contacts)
{
	Object* a = (Object*)contacts->GetFixtureA()->GetBody()->GetUserData();
	Object* b = (Object*)contacts->GetFixtureB()->GetBody()->GetUserData();

}

void PhysicsManager::PreSolve(b2Contact * contacts, const b2Manifold * oldManifold)
{
}

void PhysicsManager::EndContact(b2Contact * contacts)
{
}


