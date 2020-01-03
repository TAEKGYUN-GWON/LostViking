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

