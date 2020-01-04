#pragma once
#include "Object.h"
#include "StateComponent.h"
#include "PhysicsBodyComponent.h"

class Character : public Object
{
protected:

	typedef Object super;

	StateComponent* _state;	
	PhysicsBodyComponent* _physics;
	Inventory* _inventory;
	//Object 

	Vector2 _LadderPos;

	//int count;							//
	int _hp;							//현재 체력
	float _moveSpeedX, _moveSpeedY;		//움직이는 속도	
	//float _friction;
	//float mass;

	bool _isLadder, _isLaddering;		//사다리 충돌중 판단
	bool _isGround;						//땅입니까?
	bool _isFloating;					//떨어지고 있습니까
	bool _isPush;						//벽을 밀고있습니까
	bool _isDead;						//야,야야,죽었냐?
	bool _isActive;						//오브젝트와의 상호작용

	bool _isTurn;
public:
	Character();
	~Character();

	virtual void Init(float spawnX, float spawnY);
	virtual void Update();
	virtual void Release();

	virtual void KeyControl();
	void PosCorrection(Object* obj);

	void NormalMove(b2Vec2 b2v, float power);
	void SlowMove(b2Vec2 b2c, float power);

	void CheckLR();
	void ChangeImage(string key);

	void SetState(Object_STATE state) { _state->SetState(state); }

	void SetHP(int amount) { _hp += amount; };
	int GetHP() { return _hp; }


	void SetLadder(bool ladder) { _isLadder = ladder; }
	void SetPush(bool push) { _isPush = push; }
	void SetGround(bool ground) { _isGround = ground; }
	void DeadSetting(Object_STATE objStat) { _isDead = true; _state->SetState(objStat); }

	bool GetLadder() { return _isLadder; };

	void SetGravity(float gravity) { _physics->GetBody()->SetGravityScale(gravity); }

	virtual void Special1() {};
	virtual void Special2() {};

	void Correction(Vector2 LadderPos) { _LadderPos = LadderPos; }
	bool GetTurn() { return _isTurn; }
	void SetTurn(bool turn) { _isTurn = turn; }
	Inventory* GetInventory() { return _inventory; }
};

