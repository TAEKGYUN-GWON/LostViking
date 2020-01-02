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

	Vector2 _lastPos;

	int count;							//
	int _hp;							//���� ü��
	float _moveSpeedX, _moveSpeedY;		//�����̴� �ӵ�	
	float _friction;

	float mass;

	bool _isLadder, _isLaddering;		//��ٸ� �浹�� �Ǵ�
	bool _isGround;						//���Դϱ�?
	bool _isFloating;					//�������� �ֽ��ϱ�
	bool _isPush;						//���� �а��ֽ��ϱ�
	bool _isDead;						//��,�߾�,�׾���?
	bool _isActive;						//������Ʈ���� ��ȣ�ۿ�

public:
	Character();
	~Character();

	virtual void Init();
	virtual void Update();
	virtual void Release();

	void KeyControl();
	void PosCorrection();

	void SetState(Object_STATE state) { _state->SetState(state); }

	void SetHP(int amount) { _hp = amount; };
	int GetHP() { return _hp; }


	void SetLadder(bool ladder) { _isLadder = ladder; }
	void SetPush(bool push) { _isPush = push; }
	void DeadSetting() { _isDead = true; }

	bool GetLadder() { return _isLadder; };

	void SetGravity(float gravity) { _physics->GetBody()->SetGravityScale(gravity); }

	string GetTag() { return _tag; }

	void Idle(string key);
	void Death(string key);
	void Floating(string key);
	void Hit(string key);
	void Move(string key);
	void Ladder(string key);

	virtual void Special1() {};
	virtual void Special2() {};



};

