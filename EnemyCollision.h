#pragma once
#include "Collider.h"


class EnemyCollision :	public Collider
{

public:
	EnemyCollision();
	~EnemyCollision();

	virtual void CollisionBegin(void* obj) override;
	virtual void CollisionEnd(void* obj) override;
};

