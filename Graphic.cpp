#include "stdafx.h"
#include "Graphic.h"

ID2D1HwndRenderTarget* Graphic::_RT = nullptr;

HRESULT Graphic::Init(ID2D1Bitmap* bitmap, tagGraphicInfo graphicInfo)
{
	_bitmap = bitmap;
	_graphicInfo = graphicInfo;

	_size.x = (float)_bitmap->GetPixelSize().width;
	_size.y = (float)_bitmap->GetPixelSize().height;

	_scale = Vector2(1.0f, 1.0f);
	_alpha = 1.0f;
	_angle = 0.0f;

	return S_OK;
}

void Graphic::Release()
{
	_bitmap->Release();
	_bitmap = nullptr;
}

void Graphic::Render(float x, float y)
{
	_size.x = _size.x * _scale.x;
	_size.y = _size.y * _scale.y;

	Matrix3x2F rotation = Matrix3x2F::Rotation(_angle, Point2F());
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);

	D2D1_RECT_F dxArea = RectF(-_size.x / 2, -_size.y / 2, _size.x / 2, _size.y / 2);

	_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans);
	if(_bitmap) _RT->DrawBitmap(_bitmap, dxArea);
}
