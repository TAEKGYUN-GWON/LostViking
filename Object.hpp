#include "Object.h"
template<typename T>
vector<T*> Object::GetComponents()
{
	vector<T*> componentsList;
	for (auto c : _components)
	{
		if (dynamic_cast<T*>(c))
			componentsList.push_back((T*)c);
	}
	return componentsList;
}

#pragma once
template<typename T>
T* Object::AddComponent()
{
	Component* component = new T();

	component->setGameObject(this);
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
