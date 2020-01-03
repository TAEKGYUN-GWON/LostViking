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

	Olaf* o = new Olaf;
	o->Init(WINSIZEX / 2 - 300, 300);

	_vPlayer.push_back(o);
	//_vPlayer.push_back(c);
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

