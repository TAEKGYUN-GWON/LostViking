#pragma once

#pragma comment(lib, "d2d1.lib")
#include <d2d1.h>
#include <d2d1_1helper.h>

#pragma comment(lib, "windowscodecs.lib")
#include <wincodec.h>

#pragma comment(lib, "dwrite.lib")
#include <dwrite.h>

class Graphic
{
private:
	// d2d 
	ID2D1Factory*			_d2dFactory;
	ID2D1HwndRenderTarget*	_renderTarget;

	IWICImagingFactory*		_wicFactory;
	ID2D1Bitmap*			_bitmap;


public:
	Graphic();
	~Graphic();

	void DrawLine(int startX, int startY, int destX, int destY);
	void DrawLine(float startX, float startY, float destX, float destY);
	void DrawRect(float x, float y, float width, float height);
	void DrawRoundRect(float x, float y, float width, float height, float radiusX, float radiusY);
	void DrawEllipse(float x, float y, float radiusX, float radiusY);

	ID2D1HwndRenderTarget* GetRenderTarget() { return _renderTarget; }
};
