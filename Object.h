#pragma once

#include "Component.h"
#include <vector>

class TransformComponent;
class GraphicComponent;


class Object
{
protected:
	TransformComponent* _trans;
	GraphicComponent *_graphic;
	vector <Component*> _components;
	string _name;
	string _tag;
	bool _isActive = true;
	bool allawsUpdate = true;

public:
	Object();
	~Object() {};
	virtual void Init() {};
	virtual void Update();
	virtual void Release();
	virtual void Render();

	virtual inline TransformComponent* GetTrans() { return _trans; }
	inline string GetName() { return _name; }
	inline void SetName(string name) { _name = name; }
	inline string GetTag() { return _tag; }
	inline void SetTag(string tag) { _tag = tag; }
	inline void SetIsActive() { _isActive = !_isActive; }
	inline void SetIsActive(bool active) { _isActive = active; }
	inline bool GetIsActive() { return _isActive; }
	inline bool GetAllawsUpdate() { return allawsUpdate; }
	inline void SetAllawsUpdate() { allawsUpdate = !allawsUpdate; }
	inline void SetAllawsUpdate(bool active) { allawsUpdate = active; }
	
	inline GraphicComponent* GetGraphic() { return _graphic; }
	void RemoveComponent(Component* component);
	template<typename T>
	T* AddComponent();

	template<typename T>
	T* GetComponent();

	template<typename T>
	vector<T*> GetComponents();
};

#include "Object.hpp"