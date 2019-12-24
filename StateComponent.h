#pragma once
class Object;
enum Object_STATE
{

};
class StateComponent
{
	Object *_object;
	Object_STATE _state;
public:
	StateComponent(Object* object);
	~StateComponent();
	inline Object_STATE GetState() { return _state; }
	inline void SetState(Object_STATE state) { _state = state; }
	
};

