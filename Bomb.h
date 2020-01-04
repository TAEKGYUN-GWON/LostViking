#pragma once
#include "Item.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

class Bomb : public Item
{
private:
	float _timer;
	bool _isBomb;
	bool _isCol;

	PhysicsBodyComponent* _physic;
protected:
	typedef Item super;
public:
	virtual void Init() {};
	virtual void Init(Vector2 pos);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Ability();
	void IsExplosion(Vector2 pos);
	inline void SetBomb(bool isBomb) { _isBomb = isBomb; }
	inline bool GetBomb() { return _isBomb; }
	inline void SetCollision(bool isCol) { _isCol = isCol; }
	inline bool GetCollision() { return _isCol; }
	
};

