#pragma once
enum class Component_Type
{
	GRAPHIC,
	KEYCONTRO,
	TRANS,
	STATE,
	PHYSICS
};
class Object;

class Component abstract
{
protected:
	Object *_object;
	string _name;
	Component_Type _type;
public:
	virtual void Init() {};
	virtual void Update() {};
	virtual void Release() {};
	inline void setGameObject(Object* obj) { _object = obj; }
	inline Object* GetGameObject() { return _object; }
	inline Component_Type GetType() { return _type; }
	inline string GetName() { return _name; }
};

