#pragma once
#include "Object.h"
#include"PhysicsBodyComponent.h"
#include"State.h"
class Player : public Object
{
protected:
	typedef Object super;

	State* _state;
	PhysicsBodyComponent* _physics;
	Vector2 _LadderPos;
	Vector2 _LadderScale;
	string _playerName;
	int _hp;
	bool _isTurn;
	bool _laddering;
	float _speed;
public:
	Player();
	~Player();

	virtual void Init(Vector2 pos, string name);
	virtual void Release();
	virtual void Update();
	virtual void KeyCon();
	virtual void ImgCon();

	virtual void Epic1() {};
	virtual void Epic2() {};


	inline void HitPlayer() { --_hp; }
	inline void HealPlayer() { ++_hp; }
	inline void KillPlayer() { _hp = 0; }
	bool PlayerDead();
	inline void SetLadderPos(Vector2 pos) { _LadderPos = pos; }
	inline void SetLadderScale(Vector2 scale) { _LadderScale = scale; }
	inline void SetTurn() { _isTurn = !_isTurn; }
	inline bool GetTurn() { return _isTurn; }
	inline void SetState(STATE state) { _state->state = state; }
	inline STATE GetState() { return _state->state; }
	inline void SetLaddering(bool to) { _laddering = to; }
	
};

