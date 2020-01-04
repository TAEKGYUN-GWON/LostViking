#include "stdafx.h"
#include "PlayerScript.h"
#include"TransformComponent.h"
#include"PhysicsBodyComponent.h"

PlayerScript::PlayerScript()
{
}


PlayerScript::~PlayerScript()
{
}

void PlayerScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Player* me = (Player*)_object;
	
	if (to->GetTag() == "Ladder")
	{
		me->SetLaddering(true);
		me->SetLadderPos(to->GetTrans()->pos);
		me->SetLadderScale(to->GetTrans()->scale);
		cout << "Æ®·ç" << endl;
	}
	if (to->GetName() == "Floor"||to->GetName()=="Elevator")
		me->SetState(IDLE);
	if (to->GetTag() == "Bullet"&&to->GetName() != "Arrow")
		to->SetIsActive(false);
}

void PlayerScript::CollisionPreSolve(void * obj)
{

}

void PlayerScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Player* me = (Player*)_object;

	if (to->GetTag() == "Ladder")
	{
		if (me->GetTrans()->pos.y < to->GetTrans()->pos.y)to->GetComponent<PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(false);
		else to->GetComponent<PhysicsBodyComponent>()->GetBody()->GetFixtureList()->SetSensor(true);
		me->SetLaddering(false);
		cout << "ÆÞ½º" << endl;
	}
	if (to->GetName() == "Floor" || to->GetName() == "Elevator")
		me->SetState(JUMP);
}
