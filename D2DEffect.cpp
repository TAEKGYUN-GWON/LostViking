#include "stdafx.h"
#include "D2DEffect.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"

void D2DEffect::Init(Vector2 pos)
{
	_trans->pos = pos;

	_graphic->Init(true);
	_graphic->SetImgName("effect");
	_graphic->SetFPS(6.0f);

	_physics = AddComponent<PhysicsBodyComponent>();
	_physics->Init(BodyType::DYNAMIC, 0.3f, 0.1f, 0.0f, false, true);
	_physics->GetBody()->SetGravityScale(0.1f);
}

void D2DEffect::Release()
{
}

void D2DEffect::Update()
{
	_trans->pos = _physics->GetBodyPosition();

	super::Update();
}
