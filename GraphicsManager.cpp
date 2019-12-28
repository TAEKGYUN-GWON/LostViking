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

	DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(*&_wFactory), (IUnknown**)&_wFactory);
	AddTextFormat(L"맑은고딕", 20);

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
// 정보를 담을 곳을 지역변수로 만들어서 담아 재생성할 수 있도록 수정할 것
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

void GraphicsManager::DrawImage(string key, Vector2 pos)
{
	Graphic* graphic = FindImage(key);
	if (graphic) graphic->Render(pos.x, pos.y);
}

void GraphicsManager::DrawFrameImage(string key, Vector2 pos, float curFrameX, float curFrameY)
{
	Graphic* graphic = FindImage(key);
	if (graphic) graphic->FrameRender(pos, curFrameX, curFrameY);
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

void GraphicsManager::DrawLine(Vector2 start, Vector2 dest, BRUSH_TYPE color)
{
	_renderTarget->DrawLine(Point2F(start.x, start.y), Point2F(dest.x, dest.y), _brush[color]);
}

void GraphicsManager::DrawRect(float x, float y, float width, float height, float angle, BRUSH_TYPE color)
{
	D2D1_MATRIX_3X2_F rotation = Matrix3x2F::Rotation(angle, Point2F(x, y));

	_renderTarget->SetTransform(Matrix3x2F::Identity() * rotation* CAMERA->GetMatrix());
	_renderTarget->DrawRectangle(RectF(x, y, x + width, y + height), _brush[color]);
}

void GraphicsManager::DrawRect(Vector2 pos, Vector2 size, float angle, float strokeWidth, BRUSH_TYPE color)
{
	D2D1_MATRIX_3X2_F rotation = Matrix3x2F::Rotation(angle, Point2F(pos.x, pos.y));

	_renderTarget->SetTransform(Matrix3x2F::Identity() * rotation* CAMERA->GetMatrix());

	_renderTarget->DrawRectangle(RectF(pos.x, pos.y, pos.x + size.x, pos.y + size.y), _brush[color], strokeWidth);
}

void GraphicsManager::DrawSkewRect(Vector2 pos, Vector2 size, float angle, float strokeWidth, BRUSH_TYPE color)
{
	D2D1_MATRIX_3X2_F rotation = Matrix3x2F::Rotation(angle, Point2F(pos.x, pos.y));

	_renderTarget->SetTransform(Matrix3x2F::Skew(PI / 4 * DEGREE, 0.0f, Point2F(pos.x, pos.y)) * rotation);

	_renderTarget->DrawRectangle(RectF(pos.x, pos.y, pos.x + size.x, pos.y + size.y), _brush[color], strokeWidth);
}

void GraphicsManager::DrawCenterRect(float x, float y, float width, float height, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->DrawRectangle(RectF(x - width / 2, y - height / 2, x + width / 2, y + height / 2), _brush[color]);
}

void GraphicsManager::DrawCenterRect(Vector2 pos, Vector2 size, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->DrawRectangle(RectF(pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2), _brush[color]);
}

void GraphicsManager::DrawRoundRect(float x, float y, float width, float height, float radiusX, float radiusY, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->DrawRoundedRectangle(RoundedRect(RectF(x, y, x + width, y + height), radiusX, radiusY), _brush[color]);
}

void GraphicsManager::DrawRoundRect(Vector2 pos, Vector2 size, Vector2 radius, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->DrawRoundedRectangle(RoundedRect(RectF(pos.x, pos.y, pos.x + size.x, pos.y + size.y), radius.x, radius.y), _brush[color]);
}

void GraphicsManager::DrawEllipse(float x, float y, float radiusX, float radiusY, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->DrawEllipse(Ellipse(Point2F(x, y), radiusX, radiusY), _brush[color], 3.0f);
}

void GraphicsManager::DrawFillRect(Vector2 pos, Vector2 size, float angle, BRUSH_TYPE color)
{
	D2D1_MATRIX_3X2_F rotation = Matrix3x2F::Rotation(angle, Point2F(pos.x, pos.y));

	_renderTarget->SetTransform(Matrix3x2F::Identity() * rotation* CAMERA->GetMatrix());
	_renderTarget->FillRectangle(RectF(pos.x, pos.y, pos.x + size.x, pos.y + size.y), _brush[color]);
}

void GraphicsManager::DrawFillEllipse(Vector2 pos, Vector2 radius, float angle, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->FillEllipse(Ellipse(Point2F(pos.x, pos.y), radius.x, radius.y), _brush[color]);
}

void GraphicsManager::DrawFillRoundRect(Vector2 pos, Vector2 size, Vector2 radius, BRUSH_TYPE color)
{
	_renderTarget->SetTransform(Matrix3x2F::Identity()* CAMERA->GetMatrix());
	_renderTarget->FillRoundedRectangle(RoundedRect(RectF(pos.x, pos.y, pos.x + size.x, pos.y + size.y), radius.x, radius.y), _brush[color]);
}

HRESULT GraphicsManager::AddTextFormat(wstring fontName, float size)
{
	HRESULT hr;
	IDWriteTextFormat* format = nullptr;

	hr = _wFactory->CreateTextFormat(fontName.c_str(), 0, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, size, L"ko", &format);
	
	this->_txtFormatList.insert(make_pair(fontName, format));

	if (FAILED(hr)) return hr;

	return hr;
}

void GraphicsManager::DrawTextD2D(Vector2 pos, wstring txt, int txtSize, BRUSH_TYPE color, DWRITE_TEXT_ALIGNMENT alig, wstring font)
{
	_wFactory->CreateTextLayout(txt.c_str(), txt.length(), _txtFormatList[font], txt.length() * txtSize, txtSize, &_txtLayout);

	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = txt.length();
	
	_txtLayout->SetFontSize(txtSize, range);
	_txtLayout->SetTextAlignment(alig);

	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawTextLayout(Point2F(pos.x, pos.y), _txtLayout, _brush[color]);

	_txtLayout->Release();
}

void GraphicsManager::DrawTextD2D(Vector2 pos, const char * txt, int txtSize, BRUSH_TYPE color, DWRITE_TEXT_ALIGNMENT alig, wstring font)
{
	string buffer = txt;
	wstring str;
	str.assign(buffer.begin(), buffer.end());

	_wFactory->CreateTextLayout(str.c_str(), str.length(), _txtFormatList[font], str.length() * txtSize, txtSize, &_txtLayout);

	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = str.length();

	_txtLayout->SetFontSize(txtSize, range);
	_txtLayout->SetTextAlignment(alig);

	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawTextLayout(Point2F(pos.x, pos.y), _txtLayout, _brush[color]);

	_txtLayout->Release();
}

void GraphicsManager::DrawTextD2D(Vector2 pos, wstring txt, int txtSize, float alpha, COLORREF rgb, DWRITE_TEXT_ALIGNMENT alig, wstring font)
{
	_wFactory->CreateTextLayout(txt.c_str(), txt.length(), _txtFormatList[font], txt.length() * txtSize, txtSize, &_txtLayout);

	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = txt.length();

	_txtLayout->SetFontSize(txtSize, range);
	_txtLayout->SetTextAlignment(alig);
	_txtLayout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	ID2D1SolidColorBrush* brush;
	_renderTarget->CreateSolidColorBrush(ColorF(rgb, alpha), &brush);
	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawTextLayout(Point2F(pos.x, pos.y), _txtLayout, brush);

	brush->Release();
	_txtLayout->Release();
}

void GraphicsManager::DrawTextField(Vector2 pos, wstring txt, int txtSize, int width, int height, BRUSH_TYPE color, DWRITE_TEXT_ALIGNMENT alig, wstring font)
{
	_wFactory->CreateTextLayout(txt.c_str(), txt.length(), _txtFormatList[font], width, height, &_txtLayout);

	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = txt.length();

	_txtLayout->SetFontSize(txtSize, range);
	_txtLayout->SetTextAlignment(alig);
	_txtLayout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawTextLayout(Point2F(pos.x, pos.y), _txtLayout, _brush[color]);

	_txtLayout->Release();
}

void GraphicsManager::DrawTextField(Vector2 pos, wstring txt, int txtSize, int width, int height, float alpha, COLORREF rgb, DWRITE_TEXT_ALIGNMENT alig, wstring font)
{
	_wFactory->CreateTextLayout(txt.c_str(), txt.length(), _txtFormatList[font], width, height, &_txtLayout);

	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = txt.length();

	_txtLayout->SetFontSize(txtSize, range);
	_txtLayout->SetTextAlignment(alig);
	_txtLayout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	ID2D1SolidColorBrush* brush;
	_renderTarget->CreateSolidColorBrush(ColorF(rgb, alpha), &brush);
	_renderTarget->SetTransform(Matrix3x2F::Identity());
	_renderTarget->DrawTextLayout(Point2F(pos.x, pos.y), _txtLayout, brush);

	brush->Release();
	_txtLayout->Release();
}
