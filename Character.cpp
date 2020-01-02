#include "stdafx.h"
#include "Character.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
#include "ErikScript.h"

Character::Character()
{

}

Character::~Character()
{

}

void Character::Init()
{
	_hp = 3;
	_moveSpeedX = 10.f;
	_moveSpeedY = 1.f;

	_tag = "Player";
	//_physics->Init(DYNAMIC);

	_state =  AddComponent<StateComponent>();
	_physics = AddComponent<PhysicsBodyComponent>();
	AddComponent<ErikScript>();

	_trans->SetScale(84, 100);
	_trans->SetPos(WINSIZEX / 2 - 200, 200);

	_physics->Init(DYNAMIC,.9f);

	_lastPos = _physics->GetBodyPosition();

	_state->SetState(RIGHT_IDLE);
	/*GRAPHICMANAGER->AddFrameImage("");
	_graphic->Init(true, true);
	_graphic->SetImgName();*/

	_physics->GetBody()->SetFixedRotation(true);
	_isLadder = _isLaddering = false;				//사다리 안타고있어요
	_isDead = false;								//아뇨, 안죽었어용
	_isActive = false;								//상호작용 안할꺼에용
}

void Character::Update()
{
	super::Update();

	if (!_isLadder && !_isGround)
		_isFloating = true;
	else
		_isFloating = false;

	KeyControl();

	CAMERA->SetPosition(_trans->GetPos());
	//cout << _state->GetState() << endl;
}

void Character::Release()
{
	super::Release();
}

void Character::KeyControl()
{
	
	//_trans->SetPos(_physics->GetBodyPosition());
	//_physics->SetBodyPosition();


}

void Character::PosCorrection()
{

}

void Character::Idle(string key)
{
	_graphic->SetImgName(key);
}

void Character::Death(string key)
{
	_graphic->SetImgName(key);
}

void Character::Floating(string key)
{
	_graphic->SetImgName(key);
}

void Character::Hit(string key)
{
	_graphic->SetImgName(key);
}

void Character::Ladder(string key)
{
	_graphic->SetImgName(key);
}

void Character::Move(string key)
{
	_graphic->SetImgName(key);
}