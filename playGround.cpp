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
	GRAPHICMANAGER->AddFrameImage("fatkachu", L"fatkachu.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("plasma", L"laser.png", 3, 1);
	GRAPHICMANAGER->AddImage("enemy_bullet", L"cannon_bullet.png");

	_objMgr = new ObjectManager;
	_objMgr->Init();
	_uiMgr = new UIManager;
	_uiMgr->Init();
	_enemy = new Enemy;
	_enemy->Init();

	_pos = Vector2(WINSIZEX / 2- 200, WINSIZEY / 2);
	_pos2 = Vector2(WINSIZEX / 2 + 200, WINSIZEY / 2);

	_isPlayer1 = true;

	CAMERA->SetPosition(_pos);
	CAMERA->MoveTo(_pos, 3.0f);


	return S_OK;
}

void playGround::release()
{
	gameNode::release();
	
	SAFE_OBJECT_RELEASE(_objMgr);
	SAFE_DELETE(_objMgr);
	SAFE_OBJECT_RELEASE(_uiMgr);
	SAFE_DELETE(_uiMgr);
}

void playGround::update()
{
	gameNode::update();
	BOXWORLDMANAGER->GetWorld()->Step(timeStep, velocityIterations, positionIterations);


	float speed = 90.0f;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _pos.x -= speed * TIMEMANAGER->getElapsedTime();
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _pos.x += speed * TIMEMANAGER->getElapsedTime();
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _pos.y -= speed * TIMEMANAGER->getElapsedTime();
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _pos.y += speed * TIMEMANAGER->getElapsedTime();

	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		_isPlayer1 = !_isPlayer1;
		if (_isPlayer1)
		{
			CAMERA->MoveTo(_pos, 2.0f);
		}
		else
		{
			CAMERA->MoveTo(_pos2, 2.0f);
		}
	}

	if (_isPlayer1)
	{
		if (!CAMERA->IsMoving()) CAMERA->SetPosition(_pos);
	}
	else
	{
		if (!CAMERA->IsMoving()) CAMERA->SetPosition(_pos2);
	}

	_objMgr->Update();
	_uiMgr->Update();
	_enemy->Update();
}

void playGround::render()
{
	draw();
}

void playGround::draw()
{
	_uiMgr->Render();
	_objMgr->Render();
	_enemy->Render();

	GRAPHICMANAGER->DrawRect(_pos, Vector2(50, 50), 0.0f, ColorF::Red, CENTER, 3.0f);
	GRAPHICMANAGER->DrawRect(_pos2, Vector2(50, 50), 0.0f, ColorF::Magenta, CENTER, 3.0f);

	GRAPHICMANAGER->DrawFrameImage("number", Vector2(WINSIZEX / 2 - 50, WINSIZEY / 2), 0, 0);
	GRAPHICMANAGER->DrawFrameImage("fatkachu", Vector2(WINSIZEX / 2 + 50, WINSIZEY / 2), 0, 0);
}


