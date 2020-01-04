#pragma once
#include "Character.h"
#include "Erik.h"
#include "Olaf.h"
#include "Baleog.h"



class PlayerManager
{
private:
	vector<Character*> _vPlayer;

	Erik * _erik;
	Olaf *_olaf;
	Baleog * _baleog;
	Object_STATE _state; 

public:
	PlayerManager();
	~PlayerManager();

	void Init();
	void Release();
	void Update();
	void Render();


	Erik * GetErik() { return _erik; }
	Olaf * GetOlaf() { return _olaf; }
	Baleog * GetBaleog() { return _baleog; }

	vector<Character*>* GetPlayers() { return &_vPlayer; }
};