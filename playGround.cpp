#include "stdafx.h"
#include "playGround.h"
#include "TransformComponent.h"
#include "Object.h"
#include "PhysicsBodyComponent.h"
#include "script.h"
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
	//shape - 2D 기하학 오브젝트 (ex. 원,다각형, box등)
	//rigid body - 물리적으로 단단한 오브젝트
	//fixture - body에 shape를 결속. 밀도,마찰력,반발력 부여 
	
	//중력 벡터 선언 후 물리 세계 정의 
	b2Vec2 gravity(0.0f, 9.8);
	_world = new b2World(gravity);
	_world->SetAllowSleeping(true);
	_world->SetContinuousPhysics(true);
	BOXWORLDMANAGER->SetWorld(_world);
	PHYSICSMANAGER->SetWorld(BOXWORLDMANAGER->GetWorld());
	BOXWORLDMANAGER->GetWorld()->SetContactListener(PHYSICSMANAGER);


	//시간 설정
	 timeStep = 1.0f / 60.0f;
	 velocityIterations = 8;		//충돌 체크 얼마나 할건지 (정확도 상승, 문서에서는 8과 3 권장)
	 positionIterations = 3;		//위치 체크 얼마나 할건지 

	//그 외 
	_tested = true;


	_img = GRAPHICMANAGER->AddImage("eagle", L"eagle.png");
	_img2 = GRAPHICMANAGER->AddFrameImage("fatkachu", L"fatkachu.png", 4, 1);
	_img3 = GRAPHICMANAGER->AddFrameImage("number", L"number.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("number1", L"number.png", 4, 1);
	GRAPHICMANAGER->AddImage("bg", L"bg.png");
	_curFrameX = _curFrameY = _count = 0;

	_angle = 0.0f;
	ys = new yest;
	ys->Init();
	t = new Object;
	t->GetTrans()->SetPos(WINSIZEX/2,WINSIZEY/2);

	t->GetTrans()->SetScale(100,100);
	t->SetName("t");
	t->SetTag("t");
	//t->AddComponent<script>();
	t->AddComponent<PhysicsBodyComponent>()->Init(DYNAMIC,0.5,1);

	a = new Object;
	a->GetTrans()->SetPos(WINSIZEX/2, WINSIZEY-100);
	
	a->GetTrans()->SetScale(1000, 100);
	a->SetName("a");
	a->SetTag("a");
	a->AddComponent<PhysicsBodyComponent>()->Init(STATIC,1);
	return S_OK;
}

void playGround::release()
{
	gameNode::release();

	SAFE_OBJECT_RELEASE(_img);
	SAFE_OBJECT_RELEASE(_img2);
	SAFE_OBJECT_RELEASE(_img3);

	SAFE_DELETE(_img);
	SAFE_DELETE(_img2);
	SAFE_DELETE(_img3);
}

void playGround::update()
{
	gameNode::update();

	BOXWORLDMANAGER->GetWorld()->Step(timeStep, velocityIterations, positionIterations);

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
	
		t->GetComponent<PhysicsBodyComponent>()->GetBody()->ApplyForce(Vector2::b2Left*8, t->GetComponent<PhysicsBodyComponent>()->GetBody()->GetWorldCenter(), true);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		t->GetComponent<PhysicsBodyComponent>()->GetBody()->ApplyForce(b2Vec2(8, 0), t->GetComponent<PhysicsBodyComponent>()->GetBody()->GetWorldCenter(), true);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		t->GetComponent<PhysicsBodyComponent>()->GetBody()->ApplyForce(Vector2::b2Up*300, t->GetComponent<PhysicsBodyComponent>()->GetWorldCenter(), true);
	}

	a->GetTrans()->SetPos(a->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());
	//a->GetTrans()->SetScale(a->GetComponent<PhysicsBodyComponent>()->GetBodyScale());
	a->Update();
	if(t->GetIsActive())
		t->GetTrans()->SetPos(t->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());
	else
	{
		t->GetComponent<PhysicsBodyComponent>()->SetBodyPosition();
		t->SetIsActive(true);
	}
	
	//t->GetTrans()->SetScale(t->GetComponent<PhysicsBodyComponent>()->GetBodyScale());
	t->Update();
	ys->Update();
	//cout << t->GetIsActive() << endl;
}

void playGround::render()
{
	a->Render();
	ys->Render();
	//GRAPHICMANAGER->DrawRect(t->GetTrans()->pos, t->GetTrans()->scale, t->GetComponent<PhysicsBodyComponent>()->GetBody()->GetAngle()*DEGREE);
	t->Render();
}


void playGround::draw()
{
	char buffer[128];
	sprintf_s(buffer, "DYNAMIC BODY: pos.x = %f pos.y =%f", _dynamicBody->GetPosition().x, _dynamicBody->GetPosition().y);
	TextOut(getMemDC(), 50, 50, buffer, strlen(buffer));

	sprintf_s(buffer, "DYNAMIC BODY: angle = %f", _dynamicBody->GetAngle());
	TextOut(getMemDC(), 50, 70, buffer, strlen(buffer));

	//_img->Render(WINSIZEX / 2, WINSIZEY / 2);
	//_img2->FrameRender(100, 100, _curFrameX, 0);
	//_img3->FrameRender(100, 150, _curFrameX, 0);
	//GRAPHICMANAGER->DrawImage("bg", Vector2((float)GRAPHICMANAGER->FindImage("bg")->GetWidth()/2, GRAPHICMANAGER->FindImage("bg")->GetHeight() / 2));
	GRAPHICMANAGER->DrawRect(200, 200, 200, 200, 0.0f, BRUSH_TYPE::BLUE);
	GRAPHICMANAGER->DrawRect(Vector2(200, 200), Vector2(200, 200), 45);
	GRAPHICMANAGER->DrawRect(200, 200, 200, 200, 45);
	GRAPHICMANAGER->DrawRect(1900, 200, 200, 200, 45);
	GRAPHICMANAGER->DrawFillRect(Vector2(300, 300), Vector2(100, 100), 45);
	GRAPHICMANAGER->DrawSkewRect(Vector2(300, 200), Vector2(100, 100));
	GRAPHICMANAGER->DrawSkewRect(Vector2(300, 200), Vector2(100, 100), 45);

	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2), L"test text", 25);
	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2 + 90, WINSIZEY / 2 + 50), L"test text2", 25, 0.5f, RGB(100, 100, 255));
	GRAPHICMANAGER->DrawTextField(Vector2(WINSIZEX / 2 + 300, WINSIZEY / 2), L"test text3", 25, 10, 20);
}

void playGround::FrameAnimation()
{
	_count++;
	if (_count > 15)
	{
		_curFrameX++;
		if (_curFrameX > _img2->GetMaxFrameX()) _curFrameX = 0;
		_count = 0;
	}
}
