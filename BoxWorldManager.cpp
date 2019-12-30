#include "stdafx.h"
#include "BoxWorldManager.h"
#include "singletonBase.h"


BoxWorldManager::BoxWorldManager()
{
	
}


BoxWorldManager::~BoxWorldManager()
{

}

void BoxWorldManager::Release()
{
	SAFE_DELETE(_world);
	delete _world;
}

void BoxWorldManager::CreateWorld(b2Vec2 gravity)
{
	if (_world != nullptr) return;

	_world = new b2World(gravity);
	
}

void BoxWorldManager::RemoveBody(b2Body * body)
{
	_world->DestroyBody(body);
}

void BoxWorldManager::SetWorld()
{
	if (_world != nullptr)
	{
		SAFE_DELETE(_world);
		delete _world;
	}
	b2Vec2 gravity = b2Vec2(0, 0);
	_world = new b2World(gravity);	//가상 물리 세계 만들기
	_world->SetAllowSleeping(false); //반응 빨리하고싶으면 false
}

void BoxWorldManager::SetWorld(b2World * world)
{
	if (_world == world) return;
	
	_world = world;
}
