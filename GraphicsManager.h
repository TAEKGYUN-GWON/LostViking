#pragma once
#include <map>
class GraphicsManager
{
private:
	map<int, string> cc;

public:
	static GraphicsManager* GetInstance();
	GraphicsManager();
	~GraphicsManager();
	virtual HRESULT Init();
	virtual void Release();
};