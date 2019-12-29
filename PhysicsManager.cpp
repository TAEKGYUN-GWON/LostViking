#include "stdafx.h"
#include "PhysicsManager.h"
#include "Object.h"
#include "Collider.h"
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
	auto b = (Object*) contacts->GetFixtureB()->GetBody()->GetUserData();
	//cout << "충돌" << endl;
	if (!a || !b) return;

	for (auto s : a->GetComponents<Collider>())
		s->CollisionBegin(b);
	for (auto s : b->GetComponents<Collider>())
		s->CollisionBegin(a);

}

void PhysicsManager::PreSolve(b2Contact * contacts, const b2Manifold * oldManifold)
{
	auto a = (Object*)contacts->GetFixtureA()->GetBody()->GetUserData();
	auto b = (Object*)contacts->GetFixtureB()->GetBody()->GetUserData();

	if (!a || !b) return;

	for (auto s : a->GetComponents<Collider>())
		s->CollisionPreSolve(b);
	for (auto s : b->GetComponents<Collider>())
		s->CollisionPreSolve(a);
}

void PhysicsManager::EndContact(b2Contact * contacts)
{
	auto a = (Object*)contacts->GetFixtureA()->GetBody()->GetUserData();
	auto b = (Object*)contacts->GetFixtureB()->GetBody()->GetUserData();
	//cout << "충돌" << endl;
	if (!a || !b) return;

	for (auto s : a->GetComponents<Collider>())
		s->CollisionEnd(b);
	for (auto s : b->GetComponents<Collider>())
		s->CollisionEnd(a);
}