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


};

