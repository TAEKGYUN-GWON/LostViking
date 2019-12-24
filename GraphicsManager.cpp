#include "stdafx.h"
#include "GraphicsManager.h"


GraphicsManager * GraphicsManager::GetInstance()
{
	static GraphicsManager* instance = new GraphicsManager();
	return instance;
}

GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
}

HRESULT GraphicsManager::Init()
{
	return S_OK;
}

void GraphicsManager::Release()
{
}

int GraphicsManager::why()
{
	return 0;
}
