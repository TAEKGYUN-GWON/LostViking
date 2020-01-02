#pragma once
template<typename T>
void ObjectPool::Init(int size, Object obj)
{

	ActivePool.clear();
	for (int i = 0; i < size; i++)
	{
		Object* newObj = new T;
		newObj->SetTag(obj.GetTag());
		newObj->SetName(obj.GetName());
	
		newObj->SetIsActive(false);
		pool.push(newObj);
	}
	ActivePool.reserve(size);

}