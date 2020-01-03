#include "stdafx.h"
#include "Gate.h"
#include"GraphicComponent.h"
#include "PhysicsBodyComponent.h"
#include "GateScript.h"
Gate::Gate()
{
}


Gate::~Gate()
{
}

void Gate::Init(Vector2 pos, Vector2 scale, string key, bool pBody)
{
	_tag = "Gate";
	_name = key;
	_trans->pos = pos;
	middle = pos;
	up = pos - _trans->GetScale()*70;
	down = pos + _trans->GetScale()*70;
	
	if (!pBody)
	{
		_graphic->SetImgName(key);
		_trans->scale = Vector2(_graphic->GetGraphic()->GetWidth(), _graphic->GetGraphic()->GetHeight());
	}

	if (pBody)
	{
		_trans->scale = scale;
		_pBody = AddComponent<PhysicsBodyComponent>();
		AddComponent<GateScript>();
		_pBody->Init(STATIC, 1,1,0,0,1);
		
	}
}

void Gate::Up()
{
	//for (; _trans->GetPos().y > up.y;)
		_trans->SetPos(_trans->GetPos() + Vector2(0, -2));
}

void Gate::Down()
{
	//for (; _trans->GetPos().y < down.y;)
		_trans->SetPos(_trans->GetPos() + Vector2(0, 2));

}

void Gate::Originally()
{
	if (_trans->GetPos().y < middle.y)
	{
		//for (; _trans->GetPos().y < middle.y;)
			_trans->SetPos(_trans->GetPos() + Vector2(0, 2));
	}
	else if (_trans->GetPos().y > middle.y)
	{
		//for (; _trans->GetPos().y > middle.y;)
			_trans->SetPos(_trans->GetPos() + Vector2(0, -2));
	}
}
