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
	auto a = (Object*) contacts->GetFixtureA()->GetBody()->GetUserData();
	auto b = (Object*)contacts->GetFixtureB()->GetBody()->GetUserData();

	if (!a || !b) return;

	//for (auto s : a->GetComponents<Collider>())
	//	s->OnCollisionBegin(b);
	//for (auto s : b->GetComponents<Collider>())
	//	s->OnCollisionBegin(a);
}

void PhysicsManager::PreSolve(b2Contact * contacts, const b2Manifold * oldManifold)
{
	auto a = (Object*)contacts->GetFixtureA()->GetBody()->GetUserData();
	auto b = (Object*)contacts->GetFixtureB()->GetBody()->GetUserData();

	if (!a || !b) return;

	//for (auto s : a->GetComponents<Collider>())
	//	s->OnCollisionPreSolve(b);
	//for (auto s : b->GetComponents<Collider>())
	//	s->OnCollisionPreSolve(a);
}

void PhysicsManager::EndContact(b2Contact * contacts)
{
	auto a = (Object*)contacts->GetFixtureA()->GetBody()->GetUserData();
	auto b = (Object*)contacts->GetFixtureB()->GetBody()->GetUserData();

	if (!a || !b) return;

	//for (auto s : a->GetComponents<Collider>())
	//	s->OnCollisionEnd(b);
	//for (auto s : b->GetComponents<Collider>())
	//	s->OnCollisionEnd(a);
}