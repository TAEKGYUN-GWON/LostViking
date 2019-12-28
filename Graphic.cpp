#include "stdafx.h"
#include "Graphic.h"


ID2D1HwndRenderTarget* Graphic::_RT = nullptr;

void Graphic::SetRendertarget()
{
	assert(_RT == nullptr);
	_RT = GRAPHICMANAGER->GetRenderTarget(); 
}

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

HRESULT Graphic::Init(ID2D1Bitmap * bitmap, int maxFrameX, int maxFrameY)
{
	_graphicInfo = new GRAPHIC_INFO;
	_graphicInfo->bitmap = bitmap;

	_graphicInfo->size.x = (float)_graphicInfo->bitmap->GetPixelSize().width;
	_graphicInfo->size.y = (float)_graphicInfo->bitmap->GetPixelSize().height;

	_graphicInfo->scale = Vector2(1.0f, 1.0f);
	_graphicInfo->alpha = 1.0f;
	_graphicInfo->angle = 0.0f;
	_graphicInfo->frameWidth = _graphicInfo->size.x / maxFrameX;
	_graphicInfo->frameHeight = _graphicInfo->size.y / maxFrameY;
	_graphicInfo->maxFrameX = maxFrameX;
	_graphicInfo->maxFrameY = maxFrameY;

	if (_graphicInfo->bitmap == nullptr)
	{
		Release();
		return E_FAIL;
	}


	WICRect rc;
	for (int i = 0; i < _graphicInfo->maxFrameY; ++i)
	{
		for (int j = 0; j < _graphicInfo->maxFrameX; ++j)
		{
			rc.X = _graphicInfo->frameWidth * j;
			rc.Y = _graphicInfo->frameHeight * i;
			rc.Width = _graphicInfo->frameWidth;
			rc.Height = _graphicInfo->frameHeight;
			_vFrameRect.push_back(rc);
		}
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
	//D2D1_RECT_F dxArea = RectF(_graphicInfo->size.x, _graphicInfo->size.y, _graphicInfo->size.x , _graphicInfo->size.y);


	_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans* CAMERA->GetMatrix());
	if(_graphicInfo->bitmap) _RT->DrawBitmap(_graphicInfo->bitmap, dxArea, _graphicInfo->alpha);

}

void Graphic::FrameRender(float x, float y, int curFrameX, int curFrameY)
{
	int currentFrameX = curFrameX;
	int currentFrameY = curFrameY;

	if (currentFrameX > _graphicInfo->maxFrameX - 1) currentFrameX = _graphicInfo->maxFrameX - 1;
	if (currentFrameY > _graphicInfo->maxFrameY - 1) currentFrameY = _graphicInfo->maxFrameY - 1;

	int frame = currentFrameY * _graphicInfo->maxFrameX + currentFrameX;

	_graphicInfo->size.x *= _graphicInfo->scale.x;
	_graphicInfo->size.y *= _graphicInfo->scale.y;

	Matrix3x2F rotation = Matrix3x2F::Rotation(_graphicInfo->angle, Point2F());
	Matrix3x2F trans = Matrix3x2F::Translation(x, y);

	D2D1_RECT_F dxArea = RectF(-_graphicInfo->size.x / 2 / (_graphicInfo->maxFrameX), -_graphicInfo->size.y / 2, _graphicInfo->size.x / 2 / (_graphicInfo->maxFrameX), _graphicInfo->size.y / 2);

	D2D1_RECT_F dxSrc = RectF(_vFrameRect[frame].X, _vFrameRect[frame].Y, _vFrameRect[frame].X + _vFrameRect[frame].Width, _vFrameRect[frame].Y + _vFrameRect[frame].Height);

	_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans* CAMERA->GetMatrix());
	if (_graphicInfo->bitmap) _RT->DrawBitmap(_graphicInfo->bitmap, &dxArea, _graphicInfo->alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &dxSrc);
}

void Graphic::FrameRender(Vector2 pos, int curFrameX, int curFrameY)
{
	int currentFrameX = curFrameX;
	int currentFrameY = curFrameY;

	if (currentFrameX > _graphicInfo->maxFrameX - 1) currentFrameX = _graphicInfo->maxFrameX - 1;
	if (currentFrameY > _graphicInfo->maxFrameY - 1) currentFrameY = _graphicInfo->maxFrameY - 1;

	int frame = currentFrameY * _graphicInfo->maxFrameX + currentFrameX;

	_graphicInfo->size.x *= _graphicInfo->scale.x;
	_graphicInfo->size.y *= _graphicInfo->scale.y;

	//Matrix3x2F scale = Matrix3x2F::Scale();
	Matrix3x2F rotation = Matrix3x2F::Rotation(_graphicInfo->angle, Point2F());
	Matrix3x2F trans = Matrix3x2F::Translation(pos.x, pos.y);

	D2D1_RECT_F dxArea = RectF(-_graphicInfo->size.x / 2 / (_graphicInfo->maxFrameX), -_graphicInfo->size.y / 2, _graphicInfo->size.x / 2 / (_graphicInfo->maxFrameX), _graphicInfo->size.y / 2);

	D2D1_RECT_F dxSrc = RectF(_vFrameRect[frame].X, _vFrameRect[frame].Y, _vFrameRect[frame].X + _vFrameRect[frame].Width, _vFrameRect[frame].Y + _vFrameRect[frame].Height);


	//D2D1_MATRIX_3X2_F cameraMatrix;
	//cameraMatrix = Matrix3x2F::Scale(D2D1::SizeF(1, 1));
	//cameraMatrix = cameraMatrix * Matrix3x2F::Rotation(0);
	//cameraMatrix = cameraMatrix * Matrix3x2F::Translation(100, 100);
	//Matrix3x2F::in // ¿ªÇà·Ä


	//_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans * cameraMatrix);
	//_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans);

	_RT->SetTransform(Matrix3x2F::Identity() * rotation * trans * CAMERA->GetMatrix());
	if (_graphicInfo->bitmap) _RT->DrawBitmap(_graphicInfo->bitmap, &dxArea, _graphicInfo->alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &dxSrc);
}
