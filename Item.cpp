#include "stdafx.h"
#include "Item.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"

void Item::Init()
{
	_name = "Item";
	_tag  = "Item";


}

void Item::Init(Vector2 pos)
{
}

void Item::Release()
{

	super::Release();
}

void Item::Update()
{


	super::Update();
}

void Item::Ability()
{

}
