#pragma once
#include "Character.h"
#include "StateComponent.h"
#include "Graphic.h"

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

	void Draw();

};