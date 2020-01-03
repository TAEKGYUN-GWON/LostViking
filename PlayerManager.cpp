#include "stdafx.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

void PlayerManager::Init()
{
	Character* c = new Character;
	c->Init();


	_vPlayer.push_back(c);
}

void PlayerManager::Release()
{

}

void PlayerManager::Update()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->Update();
	}
}

void PlayerManager::Render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->Render();
	}
}

void PlayerManager::Draw()
{
	//���¿� ���� �ٸ� �׸� �־��ֱ�
	//�׸� �Է��� ���¿����� ���⼭ �� ���ְ�?
	//Ű���� ĳ���͸��� �ޱ�?
	
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_state = _vPlayer[i]->GetState()->GetState();

		switch (_state)
		{
			case RIGHT_IDLE:
				
			break;
			case LEFT_IDLE:

			break;
			case RIGHT_MOVE:
			break;
			case LEFT_MOVE:
			break;
			case RIGHT_DEATH:
			break;
			case LEFT_DEATH:
			break;
			case RIGHT_PUSH:
			break;
			case LEFT_PUSH:
			break;
			case RIGHT_HIT:
			break;
			case LEFT_HIT:
			break;
			case RIGHT_FLOATING:
			break;
			case LEFT_FLOATING:
			break;
			case RIGHT_SPECIAL1:
			break;
			case LEFT_SPECIAL1:
			break;
			case RIGHT_SPECIAL2:
			break;
			case LEFT_SPECIAL2:
			break;
			case LADDER:
			break;

		}
	}


	
}

