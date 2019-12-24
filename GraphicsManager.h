#pragma once
#include <map>
class GraphicsManager
{
private:
	map<int, string> cc;
	map<int, string> cc2;


public:
	static GraphicsManager* GetInstance();
	GraphicsManager();
	~GraphicsManager();
	virtual HRESULT Init();
	virtual void Release();
};
