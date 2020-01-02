#pragma once
#include "Character.h"

class PlayerManager
{
private:
	vector<Character> _vPlayer;

public:
	PlayerManager();
	~PlayerManager();

	void Init();
	void Release();
	void Update();
	void Render();

};