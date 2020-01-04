#pragma once
#include "Component.h"
enum Object_STATE
{
	RIGHT_IDLE,
	LEFT_IDLE,
	RIGHT_MOVE,
	LEFT_MOVE,
	RIGHT_DEATH,
	LEFT_DEATH,
	RIGHT_PUSH,
	LEFT_PUSH,
	RIGHT_HIT,
	LEFT_HIT,
	RIGHT_FLOATING,
	LEFT_FLOATING,
	RIGHT_SPECIAL1,
	LEFT_SPECIAL1,
	RIGHT_SPECIAL2,
	LEFT_SPECIAL2,
	LADDER,
	EXTRA1,
	EXTRA2,
	EXTRA3,
	EXTRA4,
	O_LEFT_SHIELD_CONTROL,
	O_RIGHT_SHIELD_CONTROL
}; 

//extra 1, 2, 3, 4문지예가 추가
//올라프 머리위로 방패들고 움직이는거, 전기로 죽는거 등 필요해서 넣음

class StateComponent : public Component
{
	Object_STATE _objState;

public:
	StateComponent() { _name = "StateComponent"; }
	inline Object_STATE GetState() { return _objState; }
	inline void SetState(Object_STATE state) { _objState = state; }

	//inline void SetDirection() { _direction *= -1; }
	//inline int GetDirection() { return _direction; }


};



