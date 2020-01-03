#pragma once
#include "Character.h"
#include "Erik.h"


class PlayerManager
{
private:
	vector<Character*> _vPlayer;

	Erik * _erik;

	Object_STATE _state; 

public:
	PlayerManager();
	~PlayerManager();

	void Init();
	void Release();
	void Update();
	void Render();


};