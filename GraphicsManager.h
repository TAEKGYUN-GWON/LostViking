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

namespace Brush_type
{
	enum Enum
	{
		WHITE,
		BLACK,
		BLUE,
		RED,
		YELLOW,
		GRAY,
		GREEN,
		MAGENTA,
		AQUAMARINE,
		BRUSH_NONE,
	};
}

class GraphicsManager : public singletonBase<GraphicsManager>
{
private:
	typedef map<string, Graphic*>							mapImageList;
	typedef map<string, Graphic*>::iterator					mapImageIter;
	typedef map<wstring, IDWriteTextFormat*>				mapTxtFormatList;
	typedef map<wstring, IDWriteTextFormat*>::iterator		mapTxtFormatIter;

private:
	mapImageList								_mImageList;

	// d2d 
	ID2D1Factory*								_d2dFactory;
	ID2D1HwndRenderTarget*						_renderTarget;

	//ID2D1RenderTarget*							_render;
	//ID2D1Device*								_device;
	//ID2D1DeviceContext*							_deviceContext;

	// wic
	IWICImagingFactory*							_wicFactory;
	IWICFormatConverter*						_wicConvert;

	IDWriteFactory*								_wFactory;
	mapTxtFormatList							_txtFormatList;
	IDWriteTextLayout*							_txtLayout;

	ID2D1SolidColorBrush*						_brush[Brush_type::BRUSH_NONE];

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
	Graphic* AddFrameImage(string key, wstring file, int maxFrameX, int maxFrameY);

	Graphic* FindImage(string strKey);
	BOOL DeleteImage(string strKey);
	BOOL DeleteAll();

	void Reload();

	void DrawImage(string key, float x, float y, PIVOT pivot = PIVOT::CENTER);
	void DrawImage(string key, Vector2 pos, PIVOT pivot = PIVOT::CENTER);

	void DrawFrameImage(string key, Vector2 pos, float curFrameX, float curFrameY, PIVOT pivot = PIVOT::CENTER);

	void DrawLine(int startX, int startY, int destX, int destY, Brush_type::Enum color = Brush_type::BLACK);
	void DrawLine(float startX, float startY, float destX, float destY, Brush_type::Enum color = Brush_type::BLACK);
	void DrawLine(Vector2 start, Vector2 dest, Brush_type::Enum color = Brush_type::BLACK);

	void DrawRect(float x, float y, float width, float height, float angle = 0.0f, Brush_type::Enum color = Brush_type::BLACK);
	void DrawRect(Vector2 pos, Vector2 size, float angle = 0.0f, float strokeWidth = 1.0f, Brush_type::Enum color = Brush_type::BLACK);
	void DrawRect(Vector2 pos, Vector2 size, float angle = 0.0f, ColorF::Enum color = ColorF::Black, PIVOT pivot = PIVOT::CENTER, float strokeWidth = 1.0f);
	void DrawRect(Vector2 pos, Vector2 size, float angle = 0.0f, Brush_type::Enum brush = Brush_type::Enum::BLACK, PIVOT pivot = PIVOT::CENTER, float strokeWidth = 1.0f);
	void DrawSkewRect(Vector2 pos, Vector2 size, float angle = 0.0f, float strokeWidth = 1.0f, Brush_type::Enum color = Brush_type::BLACK);

	void DrawRoundRect(float x, float y, float width, float height, float radiusX, float radiusY, Brush_type::Enum color = Brush_type::BLACK);
	void DrawRoundRect(Vector2 pos, Vector2 size, Vector2 radius, Brush_type::Enum color = Brush_type::BLACK);

	void DrawEllipse(float x, float y, float radiusX, float radiusY, Brush_type::Enum color = Brush_type::BLACK);

	void DrawFillRect(Vector2 pos, Vector2 size, float angle = 0.0f, Brush_type::Enum color = Brush_type::BLACK, PIVOT pivot = PIVOT::CENTER);
	void DrawFillEllipse(Vector2 pos, Vector2 radius, float angle = 0.0f, Brush_type::Enum color = Brush_type::BLACK);
	void DrawFillRoundRect(Vector2 pos, Vector2 size, Vector2 radius, Brush_type::Enum color = Brush_type::BLACK);

	HRESULT AddTextFormat(wstring fontName, float size);

	// txtSize : ±Û¾¾ Å©±â (±Û¾¾ ±æÀÌ X)
	void DrawTextD2D(Vector2 pos, wstring txt, int txtSize, Brush_type::Enum color = Brush_type::BLACK, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	void DrawTextD2D(Vector2 pos, wstring txt, int txtSize, ColorF::Enum color = ColorF::Black, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	
	void DrawTextD2D(Vector2 pos, const char* txt, int txtSize, Brush_type::Enum color = Brush_type::BLACK, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	void DrawTextD2D(Vector2 pos, const char* txt, int txtSize, ColorF::Enum color = ColorF::Black, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	
	void DrawTextD2D(Vector2 pos, wstring txt, int txtSize, float alpha, ColorF::Enum color = ColorF::Black, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	void DrawTextD2D(Vector2 pos, const char* txt, int txtSize, float alpha, ColorF::Enum color = ColorF::Black, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	
	void DrawTextField(Vector2 pos, wstring txt, int txtSize, int width, int height, Brush_type::Enum color = Brush_type::BLACK, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");
	void DrawTextField(Vector2 pos, wstring txt, int txtSize, int width, int height, float alpha, ColorF::Enum color = ColorF::Black, DWRITE_TEXT_ALIGNMENT alig = DWRITE_TEXT_ALIGNMENT_LEADING, wstring font = L"¸¼Àº°íµñ");

	ID2D1HwndRenderTarget* GetRenderTarget() { return _renderTarget; }
};

