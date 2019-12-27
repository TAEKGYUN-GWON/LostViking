#pragma once
#include "TransformComponent.h"
#include "Component.h"
#include "GraphicComponent.h"
#include <vector>

class TransformComponent;
class GraphicComponent;

class Object
{
protected:
	TransformComponent *_trans;
	vector <Component*> _components;
	string _name;
	string _tag;
	bool _isActive;

public:
	Object();
	~Object() {};
	virtual void Init() {};
	virtual void Update();
	virtual void Release();
	virtual inline TransformComponent * GetTrans() { return _trans; }
	inline string GetName() { return _name; }
	inline void SetName(string name) { _name = name; }
	inline string GetTag() { return _tag; }
	inline void SetTag(string tag) { _tag = tag; }
	inline void SetIsActive(bool active) { _isActive = active; }
	inline bool GetIsActive() { return _isActive; }
	
	void RemoveComponent(Component* component);
	template<typename T>
	T* AddComponent();
	template<typename T>
	T* GetComponent();
};

#include "Object.hpp"