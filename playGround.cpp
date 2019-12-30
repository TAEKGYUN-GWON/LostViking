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


	_img = GRAPHICMANAGER->AddImage("eagle", L"eagle.png");
	_img2 = GRAPHICMANAGER->AddFrameImage("fatkachu", L"fatkachu.png", 4, 1);
	_img3 = GRAPHICMANAGER->AddFrameImage("number", L"number.png", 4, 1);
	GRAPHICMANAGER->AddFrameImage("number1", L"number.png", 4, 1);
	GRAPHICMANAGER->AddImage("bg", L"bg.png");
	_curFrameX = _curFrameY = _count = 0;

	_pos = Vector2(WINSIZEX - 100, WINSIZEY / 2);

	_angle = 0.0f;

	_isPlayer1 = true;

	_player = new Player;
	_player->Init();

	return S_OK;
}

void playGround::release()
{
	gameNode::release();

	SAFE_OBJECT_RELEASE(_img);
	SAFE_OBJECT_RELEASE(_img2);
	SAFE_OBJECT_RELEASE(_img3);
	SAFE_OBJECT_RELEASE(_player);

	SAFE_DELETE(_img);
	SAFE_DELETE(_img2);
	SAFE_DELETE(_img3);
	SAFE_DELETE(_player);
}

void playGround::update()
{
	gameNode::update();

	_world->Step(timeStep, velocityIterations, positionIterations);
	FrameAnimation();

	_player->Update();

	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		_isPlayer1 = !_isPlayer1;
	}

	if(_isPlayer1) CAMERA->SetPosition(Vector2(_player->GetTrans()->GetPos().x - WINSIZEX / 2, _player->GetTrans()->GetPos().y - WINSIZEY / 2));
	else CAMERA->SetPosition(Vector2(_pos.x - WINSIZEX / 2, _pos.y - WINSIZEY / 2));

	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD4))
	{
		_pos += Vector2().left * 70.0f * TIMEMANAGER->getElapsedTime();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_NUMPAD6))
	{
		_pos += Vector2().right * 70.0f * TIMEMANAGER->getElapsedTime();
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD8))
	{
		_pos += Vector2().up * 70.0f * TIMEMANAGER->getElapsedTime();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_NUMPAD5))
	{
		_pos += Vector2().down * 70.0f * TIMEMANAGER->getElapsedTime();
	}

	_angle += 0.008f;
	//_img3->SetAngle(_angle * DEGREE);
}

void playGround::render()
{
	// text sample 
	char buffer[128];
	sprintf_s(buffer,"x : %f\ny:%f",Vector2::up.x, Vector2::up.y);
	GRAPHICMANAGER->DrawTextD2D(Vector2(0, 0), buffer, 20);


	draw();
}


void playGround::draw()
{
	GRAPHICMANAGER->DrawImage("bg", Vector2().zero, PIVOT::LEFT_TOP);
	_img->Render(_pos);
	//_img2->FrameRender(100, 100, _curFrameX, 0);
	//_img3->FrameRender(100, 150, _curFrameX, 0);

	_player->Render();


	GRAPHICMANAGER->DrawRect(200, 200, 200, 200, 45);
	GRAPHICMANAGER->DrawRect(1900, 200, 200, 200, 45);
	GRAPHICMANAGER->DrawSkewRect(Vector2(300, 200), Vector2(100, 100));
	GRAPHICMANAGER->DrawSkewRect(Vector2(300, 200), Vector2(100, 100), 45);

	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2), L"test text", 25);
	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2 + 50), L"test text2", 25, 0.5f, RGB(100, 100, 255));
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
