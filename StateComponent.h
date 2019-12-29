#pragma once
#include "Component.h"
enum Object_STATE
{
	RIGHT_IDLE,
	LEFT_IDLE,
	RIGHT_MOVE,
	LEFT_MOVE,
	RIGHT_PUSH,
	LEFT_PUSH,
	RIGHT_SPECIAL1,
	LEFT_SPECIAL1,
	RIGHT_SPECIAL2,
	LEFT_SPECIAL2,
	RIGHT_DEATH,
	LEFT_DEATH,
	RIGHT_FLOATING,
	LEFT_FLOATING,
	RIGHT_HIT,
	LEFT_HIT,
	LADDER
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

