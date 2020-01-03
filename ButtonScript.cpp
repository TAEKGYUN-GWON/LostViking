#include "stdafx.h"
#include "ButtonScript.h"
#include "Button.h"
#include "GraphicComponent.h"

void ButtonScript::CollisionBegin(void * obj)
{
	Object* to = (Object*)obj;
	Button* me = (Button*)_object;

	if (to->GetTag() == "Player")
	{
		//me->GetComponent<GraphicComponent>()->Stop();
		//me->GetComponent<GraphicComponent>()->Start();
		me->SetCollision(true);
		cout << "??" << endl;
	}
}

void ButtonScript::CollisionPreSolve(void * obj)
{
}

void ButtonScript::CollisionEnd(void * obj)
{
	Object* to = (Object*)obj;
	Button* me = (Button*)_object;

	if (to->GetTag() == "Player")
	{
		//me->GetComponent<GraphicComponent>()->Stop();
		//me->GetComponent<GraphicComponent>()->Start();
		me->SetCollision(false);
	}
}
