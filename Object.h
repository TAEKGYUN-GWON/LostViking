#pragma once
#include "TransformComponent.h"
#include "Component.h"
#include <vector>
class TransformComponent;

class Object
{
private:
	TransformComponent *_trans;
	vector <Component*> _components;
	string _name;
protected:

	bool _isActive;

public:
	Object() {};
	~Object() {};

	virtual HRESULT Init() {};
	virtual void Update() {};
	virtual void Release() {};
	virtual inline TransformComponent * GetTrans() { return _trans; }
	inline string GetName() { return _name; }
	inline void SetName(string name) { _name = name; }

	void RemoveComponent(Component* component);

	template<typename T>
	T* GetComponent();

	template<typename T>
	T* AddComponent();


	template<typename T>
	vector<T*>GetComponents();
};

template<typename T>
inline T * Object::GetComponent()
{
	Component* type = new T();
	for (Component* c : components)
	{
		if (c->GetType() == type->GetType())
			return (T*)c;
	}
	delete type;
	return nullptr;

}

template<typename T>
inline T * Object::AddComponent()
{
	Component* component = new T();
	component->SetGameObject(this);
	components.push_back(component);
	component->Init();

	return (T*)component;
}

template<typename T>
inline vector<T*> Object::GetComponents()
{
	Component* type = new T();
	vector<T*> componentsList;
	for (auto c : components)
	{
		if (c->GetType() == type->GetType())
			componentsList.push_back((T*)c);
	}
	delete type;
	return componentsList;
}
