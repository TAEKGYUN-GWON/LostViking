#include "stdafx.h"
#include "Graphic.h"

ID2D1HwndRenderTarget* Graphic::_RT = nullptr;

HRESULT Graphic::Init(ID2D1Bitmap* bitmap)
{
	_graphicInfo = new GRAPHIC_INFO;
	_graphicInfo->bitmap = bitmap;

	_graphicInfo->size.x = (float)_graphicInfo->bitmap->GetPixelSize().width;
	_graphicInfo->size.y = (float)_graphicInfo->bitmap->GetPixelSize().height;

	_graphicInfo->scale = Vector2(1.0f, 1.0f);
	_graphicInfo->alpha = 1.0f;
	_graphicInfo->angle = 0.0f;

	if (_graphicInfo->bitmap == nullptr)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Graphic::Init(ID2D1Bitmap * bitmap, int frameX, int frameY)
{
	_graphicInfo = new GRAPHIC_INFO;
	_graphicInfo->bitmap = bitmap;

	_graphicInfo->size.x = (float)_graphicInfo->bitmap->GetPixelSize().width;
	_graphicInfo->size.y = (float)_graphicInfo->bitmap->GetPixelSize().height;

	_graphicInfo->scale = Vector2(1.0f, 1.0f);
	_graphicInfo->alpha = 1.0f;
	_graphicInfo->angle = 0.0f;
	_graphicInfo->frameWidth = _graphicInfo->size.x / frameX;
	_graphicInfo->frameHeight = _graphicInfo->size.y / frameY;
	_graphicInfo->maxFrameX = frameX - 1;
	_graphicInfo->maxFrameY = frameY - 1;


	if (_graphicInfo->bitmap == nullptr)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Graphic::Release()
{
	if (_graphicInfo)
	{
		_graphicInfo->bitmap->Release();
		_graphicInfo->bitmap = nullptr;
	}
}

void Graphic::Render(float x, float y)
{
	_graphicInfo->size.x *= _graphicInfo->scale.x;
	_graphicInfo->size.y *= _graphicInfo->scale.y;

	Matrix3x2F rotation = Matrix3x2F::Rotation(_graphicInfo->angle, Point2F());
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);

	D2D1_RECT_F dxArea = RectF(-_graphicInfo->size.x / 2, -_graphicInfo->size.y / 2, _graphicInfo->size.x / 2, _graphicInfo->size.y / 2);

	_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans);
	if(_graphicInfo->bitmap) _RT->DrawBitmap(_graphicInfo->bitmap, dxArea);
}

void Graphic::FrameRender(float x, float y, int curFrameX, int curFrameY)
{
	_graphicInfo->size.x *= _graphicInfo->scale.x;
	_graphicInfo->size.y *= _graphicInfo->scale.y;

	Matrix3x2F rotation = Matrix3x2F::Rotation(_graphicInfo->angle, Point2F());
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);

	D2D1_RECT_F dxArea = RectF(-_graphicInfo->size.x / 2, -_graphicInfo->size.y / 2, _graphicInfo->size.x / 2, _graphicInfo->size.y / 2);

	D2D1_RECT_F dxSrc = RectF(-_graphicInfo->size.x / 2, -_graphicInfo->size.y / 2, _graphicInfo->size.x / 2, _graphicInfo->size.y / 2);

	_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans);
	if (_graphicInfo->bitmap) _RT->DrawBitmap(_graphicInfo->bitmap, &dxArea, _graphicInfo->angle, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &dxSrc);
}
