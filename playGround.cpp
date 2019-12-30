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
	
	return S_OK;
}

void playGround::release()
{
	gameNode::release();

	
}

void playGround::update()
{
	gameNode::update();

	
}

void playGround::render()
{
	draw();
}


void playGround::draw()
{
	
}


