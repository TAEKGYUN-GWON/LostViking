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

//초기화는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::init()
{
	gameNode::init(true);
	//shape - 2D 기하학 오브젝트 (ex. 원,다각형, box등)
	//rigid body - 물리적으로 단단한 오브젝트
	//fixture - body에 shape를 결속. 밀도,마찰력,반발력 부여 
	
	//중력 벡터 선언 후 물리 세계 정의 
	b2Vec2 gravity(0.0f, - 10.0f);
	_world = new b2World(gravity);
	
	//1. STATIC BODY 

	//바디 정의 
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f,- 10.0f);
	_groundBody = _world->CreateBody(&groundBodyDef);

	//shape 정의 
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);	//width/2 와 height/2가 들어감

	//fixture 더하기
	_groundBody->CreateFixture(&groundBox, 0.0f);

	//2. DYNAMIC BODY (어떠한 힘이 가해져 움직일 수 있는 바디)

	//바디 정의 
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;		//타입 지정안하면 static body로 간주 
	bodyDef.position.Set(0.0f,4.0f);
	_dynamicBody = _world->CreateBody(&bodyDef);

	//shape 정의 
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	//fixture 정의
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;			//dynamic body의 fixture중 최소 한개는 0가 아닌 density 값을 가져야 함.
	fixtureDef.friction = 0.3f;			//나머지는 기본값이 들어가 있고 다른 값 원할시 여기서 설정

	_dynamicBody->CreateFixture(&fixtureDef);


	//시간 설정
	

	 timeStep = 1.0f / 60.0f;
	 velocityIterations = 8;		//충돌 체크 얼마나 할건지 (정확도 상승, 문서에서는 8과 3 권장)
	 positionIterations = 3;		//위치 체크 얼마나 할건지 

	//그 외 
	_tested = true;





	return S_OK;
}

//메모리 해제는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::release()
{
	gameNode::release();

	
}
//연산은 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::update()
{
	gameNode::update();


	_world->Step(timeStep, velocityIterations, positionIterations);

}

//여기다 그려라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
	//딱 말했다
	//_backBuffer->render(getHDC(), 0, 0);
	GRAPHICMANAGER->GetRenderTarget()->EndDraw();
}
