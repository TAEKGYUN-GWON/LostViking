#include "stdafx.h"
#include "GateScript.h"
#include "Object.h"
#include "Gate.h"
#include "PhysicsBodyComponent.h"

GateScript::GateScript()
{
}


GateScript::~GateScript()
{
}

void GateScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Gate* me = (Gate*)_object;

	if (to->GetTag() == "Player")
	{
		me->SetIsOn(true);
		//me->GetComponent< PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(true);
	}

	
}

void GateScript::CollisionPreSolve(void * obj)
{
}

void GateScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Gate* me = (Gate*)_object;

	if (to->GetTag() == "Player")
	{
		me->SetIsOn(false);
		//me->GetComponent< PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(false);
	}


}
