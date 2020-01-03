#include "stdafx.h"
#include "Button.h"
#include "GraphicComponent.h"

void Button::Init()
{
}

void Button::Init(Vector2 pos)
{
	_trans->pos = pos;
	_name = "button";
	_tag = "Button";

	

	 
}

void Button::Release()
{

	super::Release();
}

void Button::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
	super::Update();
}

void Button::Ability()
{
}
