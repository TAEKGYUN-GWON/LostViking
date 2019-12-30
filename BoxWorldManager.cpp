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
	_world = new b2World(gravity);	//���� ���� ���� �����
	_world->SetAllowSleeping(false); //���� �����ϰ������ false
}

void BoxWorldManager::SetWorld(b2World * world)
{
	if (_world == world) return;
	
	_world = world;
}
