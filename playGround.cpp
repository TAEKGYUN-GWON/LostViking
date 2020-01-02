#include "stdafx.h"
#include "playGround.h"
#include "TransformComponent.h"
#include "Object.h"
#include "PhysicsBodyComponent.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
float32 timeStep;
int32 velocityIterations;
int32 positionIterations;

playGround::playGround()
{
}

playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);
	//박스 월드 생성 및 콘텍트 리스너 세팅
	b2Vec2 gravity(0.f, 10.f);
	BOXWORLDMANAGER->CreateWorld(gravity);
	BOXWORLDMANAGER->GetWorld()->SetAllowSleeping(true);
	BOXWORLDMANAGER->GetWorld()->SetContinuousPhysics(true);
	PHYSICSMANAGER->SetWorld(BOXWORLDMANAGER->GetWorld());
	BOXWORLDMANAGER->GetWorld()->SetContactListener(PHYSICSMANAGER);

	//박스 월드 시간 세팅
	timeStep = 1.0f / 60.0f;
	velocityIterations = 8;
	positionIterations = 3;

	//=============================== 이 밑으로 init ==============================

	GRAPHICMANAGER->AddFrameImage("number", L"number.png", 4, 1);
	//GRAPHICMANAGER->AddFrameImage("fatkachu", L"fatkachu.png", 4, 1);
	GRAPHICMANAGER->AddImage("enemy_bullet", L"cannon_bullet.png");
	//■■■■■■■■■■■■■object■■■■■■■■■■■■■
	GRAPHICMANAGER->AddFrameImage("plasma", L"img/object/laser.png", 3, 1);
	GRAPHICMANAGER->AddImage("bomba", L"img/object/bomba.png");
	GRAPHICMANAGER->AddImage("tomato", L"img/object/tomato.png");
	GRAPHICMANAGER->AddFrameImage("Tower", L"img/object/cannon.png", 2, 2);
	GRAPHICMANAGER->AddImage("computer", L"img/object/computer.png");

	_objMgr = new ObjectManager;
	_objMgr->Init();
	_uiMgr = new UIManager;
	_uiMgr->Init();
	_playerMgr = new PlayerManager;
	_playerMgr->Init();

	//CAMERA->SetPosition(_pos);
	//CAMERA->MoveTo(_pos, 3.0f);


	return S_OK;
}

void playGround::release()
{
	gameNode::release();
	
	SAFE_OBJECT_RELEASE(_objMgr);
	SAFE_DELETE(_objMgr);
	SAFE_OBJECT_RELEASE(_uiMgr);
	SAFE_DELETE(_uiMgr);
	SAFE_OBJECT_RELEASE(_playerMgr);
	SAFE_DELETE(_playerMgr);
}

void playGround::update()
{
	gameNode::update();
	BOXWORLDMANAGER->GetWorld()->Step(timeStep, velocityIterations, positionIterations);

	_playerMgr->Update();
	_objMgr->Update();
	_uiMgr->Update();
}

void playGround::render()
{
	draw();
}

void playGround::draw()
{
	_uiMgr->Render();
	_objMgr->Render();
	_playerMgr->Render();
}


