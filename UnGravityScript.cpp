#include "stdafx.h"
#include "UnGravityScript.h"
#include "Object.h"
#include "PhysicsBodyComponent.h"

UnGravityScript::UnGravityScript()
{
}


UnGravityScript::~UnGravityScript()
{
}

void UnGravityScript::CollisionBegin(void * obj)
{
	Object* b = (Object*) obj;
	if (b->GetTag() == "Player")
	{
		b->GetComponent<PhysicsBodyComponent>()->GetBody()->SetGravityScale(-0.1);
	}
}

void UnGravityScript::CollisionEnd(void * obj)
{
	Object* b = (Object*)obj;
	if (b->GetTag() == "Player")
	{
		b->GetComponent<PhysicsBodyComponent>()->GetBody()->SetGravityScale(1);
	}
}
