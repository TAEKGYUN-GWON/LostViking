#pragma once
#include "Character.h"


class PlayerManager
{
private:
	vector<Character*> _vPlayer;

	Object_STATE _state; 

public:
	PlayerManager();
	~PlayerManager();

	void Init();
	void Release();
	void Update();
	void Render();


};