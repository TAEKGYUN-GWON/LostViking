#include "stdafx.h"
#include "playGround.h"
#include "TransformComponent.h"
#include "Object.h"
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
	//shape - 2D ������ ������Ʈ (ex. ��,�ٰ���, box��)
	//rigid body - ���������� �ܴ��� ������Ʈ
	//fixture - body�� shape�� ���. �е�,������,�ݹ߷� �ο� 
	
	//�߷� ���� ���� �� ���� ���� ���� 
	b2Vec2 gravity(0.0f, - 10.0f);
	_world = new b2World(gravity);
	BOXWORLDMANAGER->SetWorld(_world);
	//1. STATIC BODY 

	//�ٵ� ���� 
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f,- 10.0f);
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
	bodyDef.position.Set(0.0f,4.0f);
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


	//�ð� ����
	 timeStep = 1.0f / 60.0f;
	 velocityIterations = 8;		//�浹 üũ �󸶳� �Ұ��� (��Ȯ�� ���, ���������� 8�� 3 ����)
	 positionIterations = 3;		//��ġ üũ �󸶳� �Ұ��� 

	//�� �� 
	_tested = true;

	_player = new Player;

	_player->Init();

	_img = GRAPHICMANAGER->AddImage("eagle", L"eagle.png");
	_img2 = GRAPHICMANAGER->AddFrameImage("fatkachu", L"fatkachu.png", 4, 1);
	_img3 = GRAPHICMANAGER->AddFrameImage("number", L"number.png", 4, 1);

	_curFrameX = _curFrameY = _count = 0;

	_angle = 0.0f;

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

	_world->Step(timeStep, velocityIterations, positionIterations);
	_player->Update();
	FrameAnimation();

	_angle += 0.008f;
	_img3->SetAngle(_angle * DEGREE);
}

void playGround::render()
{
	ID2D1RenderTarget* renderTarget = GRAPHICMANAGER->GetRenderTarget();
	renderTarget->BeginDraw();

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
	//==================================================

	char buffer[128];
	sprintf_s(buffer, "DYNAMIC BODY: pos.x = %f pos.y =%f", _dynamicBody->GetPosition().x, _dynamicBody->GetPosition().y);
	TextOut(getMemDC(), 50, 50, buffer, strlen(buffer));

	sprintf_s(buffer, "DYNAMIC BODY: angle = %f", _dynamicBody->GetAngle());
	TextOut(getMemDC(), 50, 70, buffer, strlen(buffer));

	_img->Render(WINSIZEX / 2, WINSIZEY / 2);
	_img2->FrameRender(100, 100, _curFrameX, 0);
	_img3->FrameRender(100, 150, _curFrameX, 0);

	GRAPHICMANAGER->DrawRect(200, 200, 200, 200, 0.0f, BRUSH_TYPE::BLUE);
	GRAPHICMANAGER->DrawRect(Vector2(200, 200), Vector2(200, 200), 45);
	GRAPHICMANAGER->DrawRect(200, 200, 200, 200, 45);
	GRAPHICMANAGER->DrawFillRect(Vector2(300, 300), Vector2(100, 100), 45);
	GRAPHICMANAGER->DrawSkewRect(Vector2(300, 200), Vector2(100, 100));
	GRAPHICMANAGER->DrawSkewRect(Vector2(300, 200), Vector2(100, 100), 45);

	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2), L"test text", 25);
	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2 + 90, WINSIZEY / 2 + 50), L"test text2", 25, 0.5f, RGB(100, 100, 255));
	GRAPHICMANAGER->DrawTextField(Vector2(WINSIZEX / 2 + 300, WINSIZEY / 2), L"test text3", 25, 10, 20);

	GRAPHICMANAGER->DrawRect(_player->GetTrans()->GetPos(), _player->GetTrans()->GetScale(), 0.0f, BRUSH_TYPE::BLUE);

	//===================================================
	HRESULT hr = renderTarget->EndDraw();
	//if (hr == D2DERR_RECREATE_TARGET) GRAPHICMANAGER->Reload();
	if (hr == D2DERR_RECREATE_TARGET) GRAPHICMANAGER->Release();
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
