#include "stdafx.h"
#include "GraphicsManager.h"

HRESULT GraphicsManager::init()
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_d2dFactory);
	//assert(hr == S_OK);

	// wic 이미지 팩토리 생성
	CoInitialize(0);
	CoCreateInstance(CLSID_WICImagingFactory, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_wicFactory));
	//assert(hr == S_OK);

	initRenderTarget();

	return S_OK;
}

HRESULT GraphicsManager::initRenderTarget()
{
	RECT rc;
	GetClientRect(_hWnd, &rc);
	D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

	// 렌더타겟 생성
	_d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(_hWnd, size), &_renderTarget);

	// bush create
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &_brush[WHITE]);
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &_brush[BLACK]);
	_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &_brush[BLUE]);

	Graphic::SetRenderTarget(_renderTarget);

	return S_OK;
}

void GraphicsManager::Release()
{
	SafeRelease(_d2dFactory);
	SafeRelease(_renderTarget);
	SafeRelease(_wicFactory);
	SafeRelease(_wicConvert);

	for (int i = 0; i < BRUSH_NONE; ++i)
	{
		_brush[i]->Release();
	}
}

Graphic* GraphicsManager::AddImage(string key, wstring file)
{
	Graphic* graphic = FindImage(key);

	if (graphic) return graphic;

	ID2D1Bitmap* bitmap = CreateD2DBitmap(file);

	if (bitmap)
	{
		graphic = new Graphic;
		graphic->Init(bitmap);

		_mImageList.insert(make_pair(key, graphic));
		return graphic;
	}

	SafeRelease(bitmap);
	return nullptr;
}

Graphic * GraphicsManager::AddFrameImage(string key, wstring file, int maxFrameX, int maxFrameY)
{
	Graphic* graphic = FindImage(key);

	if (graphic) return graphic;

	ID2D1Bitmap* bitmap = CreateD2DBitmap(file);

	if (bitmap)
	{
		graphic = new Graphic;
		graphic->Init(bitmap, maxFrameX, maxFrameY);

		_mImageList.insert(make_pair(key, graphic));
		return graphic;
	}

	SafeRelease(bitmap);
	return nullptr;
}

Graphic * GraphicsManager::FindImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

BOOL GraphicsManager::DeleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->Release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

BOOL GraphicsManager::DeleteAll()
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->Release();
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();
	return true;
}


// FIXME : tagGraphicInfo 다르게 보관해서 불러올 수 있도록 만들어보자
// 딱히 문제 없어보이니 건들지 말아봅시다.
void GraphicsManager::Reload()
{
	vector<Graphic::tagGraphicInfo> _graphicInfoList;
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end(); ++iter)
	{
		//_graphicInfoList.emplace_back(iter->second->GetGraphicInfo());
	}

	DeleteAll();
	SafeRelease(_renderTarget);

	initRenderTarget();

	for (size_t i = 0; i < _graphicInfoList.size(); ++i)
	{
		//this->AddImage(_graphicInfoList[i].key, _graphicInfoList[i].path);
	}
}

void GraphicsManager::DrawImage(string key, float x, float y)
{
	Graphic* graphic = FindImage(key);
	if (graphic) graphic->Render(x, y);
}

ID2D1Bitmap* GraphicsManager::CreateD2DBitmap(wstring file)
{
	// 디코더 생성
	IWICBitmapDecoder* decoder = nullptr;
	_wicFactory->CreateDecoderFromFilename(file.c_str(), NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand, &decoder);

	// 디코더에서 프레임 얻음
	IWICBitmapFrameDecode* frame = nullptr;
	decoder->GetFrame(0, &frame);

	// 프레임을 기반으로 포맷 컨버터 만듬
	SafeRelease(_wicConvert);
	_wicFactory->CreateFormatConverter(&_wicConvert);
	_wicConvert->Initialize(frame, GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone, NULL, 0.0f, WICBitmapPaletteTypeCustom);

	// 컨버트된 데이터를 기반으로 실제 비트맵 만듬
	ID2D1Bitmap* bitmap = nullptr;
	_renderTarget->CreateBitmapFromWicBitmap(_wicConvert, NULL, &bitmap);

	SafeRelease(decoder);
	SafeRelease(frame);

	return bitmap;
}

void GraphicsManager::DrawLine(int startX, int startY, int destX, int destY, BRUSH_TYPE color)
{
	_renderTarget->DrawLine(Point2F(startX, startY), Point2F(destX, destY), _brush[color]);
}

void GraphicsManager::DrawLine(float startX, float startY, float destX, float destY, BRUSH_TYPE color)
{
	_renderTarget->DrawLine(Point2F(startX, startY), Point2F(destX, destY), _brush[color]);
}

void GraphicsManager::DrawRect(float x, float y, float width, float height, float angle, BRUSH_TYPE color)
{
	D2D1_MATRIX_3X2_F rotation = Matrix3x2F::Rotation(angle, Point2F(x, y));

	_renderTarget->SetTransform(Matrix3x2F::Identity() * rotation);
	_renderTarget->DrawRectangle(RectF(x, y, x + width, y + height), _brush[color]);
}

void GraphicsManager::DrawCenterRect(float x, float y, float width, float height, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawRectangle(RectF(x - width / 2, y - height / 2, x + width / 2, y + height / 2), _brush[color]);
}

void GraphicsManager::DrawRoundRect(float x, float y, float width, float height, float radiusX, float radiusY, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawRoundedRectangle(RoundedRect(RectF(x, y, x + width, y + height), radiusX, radiusY), _brush[color]);
}

void GraphicsManager::DrawEllipse(float x, float y, float radiusX, float radiusY, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawEllipse(Ellipse(Point2F(x, y), radiusX, radiusY), _brush[color], 3.0f);
}

