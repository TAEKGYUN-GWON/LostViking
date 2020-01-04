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
	_erik->Init(WINSIZEX/2-200, WINSIZEY/2);
	_olaf = new Olaf;
	_olaf->Init(WINSIZEX / 2 - 350, WINSIZEY / 2);
	_olaf->SetTurn(true);
	_vPlayer.push_back(_erik);
	_vPlayer.push_back(_olaf);

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

