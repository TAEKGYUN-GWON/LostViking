#pragma once
#include "singletonBase.h"
#include <map>

#pragma comment(lib, "d2d1.lib")
#include <d2d1.h>
#include <d2d1_1helper.h>

#pragma comment(lib, "windowscodecs.lib")
#include <wincodec.h>

#pragma comment(lib, "dwrite.lib")
#include <dwrite.h>

#include "Graphic.h"

using namespace D2D1;

enum BRUSH_TYPE
{
	WHITE,
	BLACK,
	BLUE,
	BRUSH_NONE,
};

class GraphicsManager : public singletonBase<GraphicsManager>
{
private:
	typedef map<string, Graphic*>			mapImageList;
	typedef map<string, Graphic*>::iterator mapImageIter;

private:
	mapImageList			_mImageList;

	// d2d 
	ID2D1Factory*			_d2dFactory;
	ID2D1HwndRenderTarget*	_renderTarget;

	// wic
	IWICImagingFactory*		_wicFactory;
	IWICFormatConverter*	_wicConvert;


	ID2D1SolidColorBrush*	_brush[BRUSH_NONE];

private:
	ID2D1Bitmap* CreateD2DBitmap(wstring file);

public:
	GraphicsManager() 
	{
		_d2dFactory = nullptr;
		_renderTarget = nullptr;
		_wicFactory = nullptr;
		_wicConvert = nullptr;
	};
	~GraphicsManager() {};

	HRESULT init();
	HRESULT initRenderTarget();
	void Release();

	Graphic* AddImage(string key, wstring file);
	Graphic* FindImage(string strKey);
	BOOL DeleteImage(string strKey);
	BOOL DeleteAll();

	void Reload();

	void DrawImage(string key, float x, float y);

	void DrawLine(int startX, int startY, int destX, int destY, BRUSH_TYPE color = BLACK);
	void DrawLine(float startX, float startY, float destX, float destY, BRUSH_TYPE color = BLACK);
	void DrawRect(float x, float y, float width, float height, float angle = 0.0f, BRUSH_TYPE color = BLACK);
	void DrawCenterRect(float x, float y, float width, float height, BRUSH_TYPE color = BLACK);
	void DrawRoundRect(float x, float y, float width, float height, float radiusX, float radiusY, BRUSH_TYPE color = BLACK);
	void DrawEllipse(float x, float y, float radiusX, float radiusY, BRUSH_TYPE color = BLACK);

	ID2D1HwndRenderTarget* GetRenderTarget() { return _renderTarget; }
};

