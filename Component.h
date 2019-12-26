#pragma once

class Object;

class Component abstract 
{
protected:
	Object *_object;
	string _name;
public:
	virtual void Init() {};
	virtual void Update() {};
	virtual void Release() { delete this; };
	inline void setGameObject(Object* obj) { _object = obj; }
	inline Object* GetGameObject() { return _object; }
	inline string GetName() { return _name; }
};

