#pragma once
#include"GraphicComponent.h"
#include "Bullet.h"

template<typename T>
void ObjectPool::Init(int size, Object obj)
{
	ActivePool.reserve(size);
	for (int i = 0; i < size; i++)
	{
		if (obj.GetTag() == "Bullet")
		{
			Bullet* newObj = new Bullet;
			newObj->Init(obj.GetGraphic()->GetImgKey(), obj.GetTag(), obj.GetName());
			newObj->SetIsActive(false);
			pool.push(newObj);
		}
		else
		{
			Object* newObj = new T;
			newObj->Init();
			newObj->SetTag(obj.GetTag());
			newObj->SetName(obj.GetName());
			newObj->GetGraphic()->SetImgName(obj.GetGraphic()->GetImgKey());
			newObj->SetIsActive(false);
			pool.push(newObj);
		}
	}
}