#pragma once
#include "Component.h"
enum Object_STATE
{
	IDLE,
	MOVE,
	JUMP,
	SPECIAL1,
	SPECIAL2
};
class StateComponent : public Component
{
	Object_STATE _state;
	int _direction;
public:
	StateComponent() { _name = "StateComponent"; }
	inline Object_STATE GetState() { return _state; }
	inline void SetState(Object_STATE state) { _state = state; }
	inline void SetDirection() { _direction *= -1; }
	inline int GetDirection() { return _direction; }
};

