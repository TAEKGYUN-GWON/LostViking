#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
	_tag = "Player";
	_name = "Player";
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(100, 100);

	_graphic = GetComponent<GraphicComponent>();
	_graphic->Init(true);
	_graphic->SetImgName("number");
}

void Player::Update()
{
	float speed = 75.0f;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_trans->pos += Vector2().left * speed * TIMEMANAGER->getElapsedTime();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_trans->pos += Vector2().right * speed * TIMEMANAGER->getElapsedTime();
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_trans->pos += Vector2().up * speed * TIMEMANAGER->getElapsedTime();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_trans->pos += Vector2().down * speed * TIMEMANAGER->getElapsedTime();
	}

	//CAMERA->SetPosition(Vector2(_trans->pos.x - WINSIZEX / 2, _trans->pos.y - WINSIZEY / 2));

	// frame test
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_graphic->Start();
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_graphic->Stop();
	}if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_graphic->Pause();
	}if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_graphic->Resume();
	}

	super::Update();
}

void Player::Render()
{
	super::Render();

	char str[128];
	sprintf_s(str, "curFrameX :  %d\nmaxFrameX : %d", _graphic->GetGraphic()->GetCurrentFrameX(), _graphic->GetGraphic()->GetMaxFrameX());
	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2, 40), str, 20);
	
	if (_graphic->IsFrameEnd()) GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2, 10), L"animation end", 20);
}
