#include "stdafx.h"
#include "playGround.h"
#include "TransformComponent.h"
#include "Object.h"
#include "PhysicsBodyComponent.h"
#include "Collider.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
float32 timeStep;
int32 velocityIterations;
int32 positionIterations;

playGround::playGround()
{
}

playGround::~playGround()
{
	//1. STATIC BODY 

//�ٵ� ���� 
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	_groundBody = _world->CreateBody(&groundBodyDef);

	//shape ���� 
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);	//width/2 �� height/2�� ��

	//fixture ���ϱ�
	_groundBody->CreateFixture(&groundBox, 0.0f);

	//2. DYNAMIC BODY (��� ���� ������ ������ �� �ִ� �ٵ�)

	//�ٵ� ���� 
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;		//Ÿ�� �������ϸ� static body�� ���� 
	bodyDef.position.Set(0.0f, 4.0f);
	_dynamicBody = _world->CreateBody(&bodyDef);

	//shape ���� 
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	//fixture ����
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;			//dynamic body�� fixture�� �ּ� �Ѱ��� 0�� �ƴ� density ���� ������ ��.
	fixtureDef.friction = 0.3f;			//�������� �⺻���� �� �ְ� �ٸ� �� ���ҽ� ���⼭ ����

	_dynamicBody->CreateFixture(&fixtureDef);

}

HRESULT playGround::init()
{
	gameNode::init(true);
	//shape - 2D ������ ������Ʈ (ex. ��,�ٰ���, box��)
	//rigid body - ���������� �ܴ��� ������Ʈ
	//fixture - body�� shape�� ���. �е�,������,�ݹ߷� �ο� 
	
	//�߷� ���� ���� �� ���� ���� ���� 
	b2Vec2 gravity(0.0f, 9.8);
	_world = new b2World(gravity);
	_world->SetAllowSleeping(true);
	_world->SetContinuousPhysics(true);
	BOXWORLDMANAGER->SetWorld(_world);
	PHYSICSMANAGER->SetWorld(BOXWORLDMANAGER->GetWorld());
	BOXWORLDMANAGER->GetWorld()->SetContactListener(PHYSICSMANAGER);


	//�ð� ����
	 timeStep = 1.0f / 60.0f;
	 velocityIterations = 8;		//�浹 üũ �󸶳� �Ұ��� (��Ȯ�� ���, ���������� 8�� 3 ����)
	 positionIterations = 3;		//��ġ üũ �󸶳� �Ұ��� 

	//�� �� 
	_tested = true;


	_img = GRAPHICMANAGER->AddImage("eagle", L"eagle.png");
	_img2 = GRAPHICMANAGER->AddFrameImage("fatkachu", L"fatkachu.png", 4, 1);
	_img3 = GRAPHICMANAGER->AddFrameImage("number", L"number.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("number1", L"number.png", 4, 1);
	GRAPHICMANAGER->AddImage("bg", L"bg.png");
	_curFrameX = _curFrameY = _count = 0;

	_angle = 0.0f;

	t = new Object;
	t->GetTrans()->SetPos(WINSIZEX/2,WINSIZEY/2);

	t->GetTrans()->SetScale(100,100);
	t->SetName("t");
	t->SetTag("t");
	t->AddComponent<Collider>();
	t->AddComponent<PhysicsBodyComponent>()->setGameObject(t);
	t->GetComponent<PhysicsBodyComponent>()->Init(DYNAMIC);

	a = new Object;
	a->GetTrans()->SetPos(WINSIZEX/2, WINSIZEY-100);
	
	a->GetTrans()->SetScale(1000, 100);
	a->SetName("a");
	a->SetTag("a");
	a->AddComponent<Collider>();
	a->AddComponent<PhysicsBodyComponent>()->setGameObject(a);
	a->GetComponent<PhysicsBodyComponent>()->Init(STATIC);
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


	a->GetTrans()->SetPos(a->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());
	//a->GetTrans()->SetScale(a->GetComponent<PhysicsBodyComponent>()->GetBodyScale());
	a->Update();

	t->GetTrans()->SetPos(t->GetComponent<PhysicsBodyComponent>()->GetBodyPosition());
	//t->GetTrans()->SetScale(t->GetComponent<PhysicsBodyComponent>()->GetBodyScale());
	t->Update();
}

void playGround::render()
{
	a->Render();
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
