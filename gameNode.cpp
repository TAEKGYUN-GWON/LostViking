#include "stdafx.h"
#include "gameNode.h"

gameNode::gameNode()
{
}

gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{

	_hdc = GetDC(_hWnd);
	_managerInit = false;

	
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TXTDATA->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();
		GRAPHICMANAGER->init();
		Graphic::SetRendertarget();
		CAMERA->init();
	}

	return S_OK;
}

void gameNode::release()
{
	if (_managerInit)
	{
		KillTimer(_hWnd, 1);
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		TXTDATA->release();
		TXTDATA->releaseSingleton();
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		BOXWORLDMANAGER->Release();
		BOXWORLDMANAGER->releaseSingleton();
		GRAPHICMANAGER->Release();
		GRAPHICMANAGER->releaseSingleton();
		//CAMERA->release();
		CAMERA->releaseSingleton();
	}

	ReleaseDC(_hWnd, _hdc);
}

void gameNode::update()
{
	CAMERA->Update();
}

void gameNode::render()
{
}

//LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//
//	PAINTSTRUCT ps;
//	HDC			hdc;
//
//	switch (iMessage)
//	{
//		case WM_CREATE:
//
//		break;
//	
//		case WM_MOUSEMOVE:
//			_ptMouse.x = static_cast<float>(LOWORD(lParam));
//			_ptMouse.y = static_cast<float>(HIWORD(lParam));
//		break;
//
//		case WM_KEYDOWN:
//		{
//			switch (wParam)
//			{
//				case VK_ESCAPE:
//					PostQuitMessage(0);
//				break;
//
//			}
//		}
//		break;
//
//
//		case WM_DESTROY:
//			PostQuitMessage(0);
//		break;
//	}
//
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}
