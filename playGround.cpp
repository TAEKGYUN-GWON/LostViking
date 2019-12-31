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
	
	//바닥
	a = new Object;
	a->GetTrans()->SetPos(WINSIZEX / 2, WINSIZEY - 100);
	a->GetTrans()->SetScale(1000, 100);
	a->SetName("a");
	a->SetTag("a");
	a->AddComponent<PhysicsBodyComponent>();
	a->GetComponent<PhysicsBodyComponent>()->Init(STATIC,0);

	//왼쪽 벽
	leftWall = new Object;
	leftWall->GetTrans()->SetPos(Vector2(200, WINSIZEY - 200));
	leftWall->GetTrans()->SetScale(Vector2(100, 100));
	leftWall->AddComponent<PhysicsBodyComponent>();
	leftWall->GetComponent<PhysicsBodyComponent>()->Init(STATIC, 0);

	//오른쪽 벽
	rightWall = new Object;
	rightWall->GetTrans()->SetPos(Vector2(WINSIZEX - 200, WINSIZEY - 200));
	rightWall->GetTrans()->SetScale(Vector2(100, 100));
	rightWall->AddComponent<PhysicsBodyComponent>();
	rightWall->GetComponent<PhysicsBodyComponent>()->Init(STATIC, 0);

	_enemy = new Enemy;
	_enemy->Init();

	return S_OK;
}

void playGround::release()
{
	gameNode::release();

	
}

void playGround::update()
{
	gameNode::update();
	BOXWORLDMANAGER->GetWorld()->Step(timeStep, velocityIterations, positionIterations);

	a->Update();
	a->GetTrans()->SetPos(a->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());
	leftWall->Update();
	leftWall->GetTrans()->SetPos(leftWall->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());
	rightWall->Update();
	rightWall->GetTrans()->SetPos(rightWall->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());


	_enemy->Update();

}

void playGround::render()
{
	draw();
	a->Render();
	leftWall->Render();
	rightWall->Render();
	
	_enemy->Render();
}


void playGround::draw()
{
	
}


