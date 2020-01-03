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
	/*Character* c = new Character;
	c->Init(WINSIZEX / 2 - 200, 200);*/

	_erik = new Erik;
	_erik->Init(WINSIZEX/2-200, 150);

	_vPlayer.push_back(_erik);
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

