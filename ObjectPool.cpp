#include "stdafx.h"
#include "ObjectPool.h"


ObjectPool::ObjectPool()
{
}


ObjectPool::~ObjectPool()
{
}

void ObjectPool::Init(int size, Object * obj)
{
	ActivePool.reserve(size);
	for (int i = 0; i < size; i++)
	{
		obj->SetIsActive(false);
		pool.push(obj);
	}
}

void ObjectPool::InssertPool(int num)
{
	ActivePool[num]->SetIsActive(false);
	pool.push(ActivePool[num]);
	ActivePool.erase(ActivePool.begin() + num);
}

void ObjectPool::InssertActiveObject()
{
	pool.top()->SetIsActive(true);
	ActivePool.push_back(pool.top());
	pool.pop();
}
