#include "stdafx.h"
#include "GraphicsManager.h"

GraphicsManager::GraphicsManager()
{
}

GraphicsManager::~GraphicsManager()
{
}

HRESULT GraphicsManager::init()
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_d2dFactory);

	// ����Ÿ�� ����
	hr = _d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(_hWnd, D2D1::SizeU(WINSIZEX, WINSIZEY)), &_renderTarget);
	//assert(hr == S_OK);


	// wic �̹��� ���丮 ����
	CoInitialize(0);
	CoCreateInstance(CLSID_WICImagingCategories, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_wicFactory));

	return S_OK;
}

void GraphicsManager::Release()
{
	Safe_release(_d2dFactory);
	Safe_release(_renderTarget);
}

void GraphicsManager::DrawLine(int startX, int startY, int destX, int destY)
{
	ID2D1SolidColorBrush* brush = NULL;
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &brush);

	_renderTarget->DrawLine(D2D1::Point2F(startX, startY), D2D1::Point2F(destX, destY), brush);
}

void GraphicsManager::DrawLine(float startX, float startY, float destX, float destY)
{
	ID2D1SolidColorBrush* brush = NULL;
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &brush);

	_renderTarget->DrawLine(D2D1::Point2F(startX, startY), D2D1::Point2F(destX, destY), brush);
}

void GraphicsManager::DrawRect(float x, float y, float width, float height)
{
	D2D1_RECT_F* rc;

	ID2D1SolidColorBrush* brush = NULL;
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &brush);

	rc = new D2D1_RECT_F;

	rc->left = x;
	rc->top = y;
	rc->right = x + width;
	rc->bottom = y + height;

	_renderTarget->DrawRectangle(rc, brush);
}

void GraphicsManager::DrawRoundRect(float x, float y, float width, float height, float radiusX, float radiusY)
{
	D2D1_ROUNDED_RECT* rc;

	ID2D1SolidColorBrush* brush = NULL;
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &brush);

	rc = new D2D1_ROUNDED_RECT;
	rc->rect = D2D1::RectF(x, y, x + width, y + height);
	rc->radiusX = radiusX;
	rc->radiusY = radiusY;

	_renderTarget->DrawRoundedRectangle(rc, brush);
}

void GraphicsManager::DrawEllipse(float x, float y, float radiusX, float radiusY)
{
	D2D1_ELLIPSE* ellipse;

	ID2D1SolidColorBrush* brush = NULL;
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &brush);

	ellipse = new D2D1_ELLIPSE;
	ellipse->point = D2D1::Point2F(x, y);
	ellipse->radiusX = radiusX;
	ellipse->radiusY = radiusY;

	_renderTarget->DrawEllipse(ellipse, brush);
}