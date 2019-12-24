#include "stdafx.h"
#include "playGround.h"
#include "TransformComponent.h"
float32 timeStep;
int32 velocityIterations;
int32 positionIterations;

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ض�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::init()
{
	gameNode::init(true);
	//shape - 2D ������ ������Ʈ (ex. ��,�ٰ���, box��)
	//rigid body - ���������� �ܴ��� ������Ʈ
	//fixture - body�� shape�� ���. �е�,������,�ݹ߷� �ο� 
	
	//�߷� ���� ���� �� ���� ���� ���� 
	b2Vec2 gravity(0.0f, - 10.0f);
	_world = new b2World(gravity);
	
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





	return S_OK;
}

//�޸� ������ ����� �ض�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::release()
{
	gameNode::release();

	
}
//������ ����� �ض�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::update()
{
	gameNode::update();


	_world->Step(timeStep, velocityIterations, positionIterations);

}

//����� �׷���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render()
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	GRAPHICMANAGER->GetRenderTarget();
	GRAPHICMANAGER->GetRenderTarget()->BeginDraw();
	GRAPHICMANAGER->GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::White));
	//==================================================

	char buffer[128];
	sprintf_s(buffer, "DYNAMIC BODY: pos.x = %f pos.y =%f", _dynamicBody->GetPosition().x, _dynamicBody->GetPosition().y);
	TextOut(getMemDC(), 50, 50, buffer, strlen(buffer));

	sprintf_s(buffer, "DYNAMIC BODY: angle = %f", _dynamicBody->GetAngle());
	TextOut(getMemDC(), 50, 70, buffer, strlen(buffer));

	GRAPHICMANAGER->DrawRect(WINSIZEX / 2, WINSIZEY / 2, 100, 100);


	//===================================================
	//�� ���ߴ�
	//_backBuffer->render(getHDC(), 0, 0);
	GRAPHICMANAGER->GetRenderTarget()->EndDraw();
}
