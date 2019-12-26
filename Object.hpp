#include "Object.h"
#pragma once
template<typename T>
T* Object::AddComponent()
{
	Component* component = new T();
	component->setGameObject(this);

	for (Component* itr : _components)
	{
		if (itr->GetName() == component->GetName())
			return (T*)itr;
	}
	if(component->GetName()!="PhysicsBodyComponent")
		component->Init();
	_components.push_back(component);
	return (T*)component;
}

template<typename T>
inline T * Object::GetComponent()
{
	for (Component* c : _components)
	{
		if (dynamic_cast<T*>(c))
			return (T*)c;
	}
	return nullptr;
}
