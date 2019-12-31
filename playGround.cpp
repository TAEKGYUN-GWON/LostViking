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
	//�ڽ� ���� ���� �� ����Ʈ ������ ����
	b2Vec2 gravity(0.f, 10.f);
	BOXWORLDMANAGER->CreateWorld(gravity);
	BOXWORLDMANAGER->GetWorld()->SetAllowSleeping(true);
	BOXWORLDMANAGER->GetWorld()->SetContinuousPhysics(true);
	PHYSICSMANAGER->SetWorld(BOXWORLDMANAGER->GetWorld());
	BOXWORLDMANAGER->GetWorld()->SetContactListener(PHYSICSMANAGER);

	//�ڽ� ���� �ð� ����
	timeStep = 1.0f / 60.0f;
	velocityIterations = 8;
	positionIterations = 3;

	//=============================== �� ������ init ==============================

	c = new Character;
	c->Init();

	flore = new Object;
	flore->Init();
	flore->GetTrans()->SetPos(WINSIZEX / 2, WINSIZEY - 100);
	flore->GetTrans()->SetScale(1000, 50);

	auto a = flore->AddComponent<PhysicsBodyComponent>();
	a->Init(STATIC, 0.5f);

	_ladder = new Object;
	_ladder->GetTrans()->SetPos(WINSIZEX / 2 - 200, WINSIZEY / 2 - 50);
	_ladder->GetTrans()->SetScale(20, 400);
	_ladder->SetName("LADDER");

	a = _ladder->AddComponent<PhysicsBodyComponent>();
	a->Init(STATIC, 1.f,1,0,0,1);

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
	flore->Update();
	c->Update();

}

void playGround::render()
{
	flore->Render();
	_ladder->Render();
	c->Render();
	draw();
}


void playGround::draw()
{


}


