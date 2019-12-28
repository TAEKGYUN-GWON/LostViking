#pragma once

class Graphic
{
private:
	static ID2D1HwndRenderTarget* _RT;
public:
	static void SetRendertarget();

public:
	typedef struct tagGraphicInfo
	{
		ID2D1Bitmap*				bitmap;
		Vector2						size;
		Vector2						scale;
		float						angle;
		float						alpha;
		int							frameWidth;
		int							frameHeight;
		int							maxFrameX;
		int							maxFrameY;

		tagGraphicInfo()
		{
			bitmap = nullptr;
			size = Vector2(1.0f, 1.0f);
			scale = Vector2(1.0f, 1.0f);
			angle = 0.0f;
			alpha = 1.0f;
			frameWidth = 0;
			frameHeight = 0;
			maxFrameX = 0;
			maxFrameY = 0;
		}
	}GRAPHIC_INFO, *LPGRAPHIC_INFO;

private:
	LPGRAPHIC_INFO					_graphicInfo;

	vector<WICRect>					_vFrameRect;
	vector<WICRect>::iterator		_viFrameRect;

public:
	Graphic() {};
	~Graphic() {};

	HRESULT Init(ID2D1Bitmap* bitmap);
	HRESULT Init(ID2D1Bitmap* bitmap, int maxFrameX, int maxFrameY);
	void Release();
	void Render(float x, float y);
	void FrameRender(float x, float y, int curFrameX, int curFrameY);
	void FrameRender(Vector2 pos, int curFrameX, int curFrameY);
	
	void SetSize(Vector2 size) { _graphicInfo->size = size; }
	void SetAngle(float angle) { _graphicInfo->angle = angle; }
	void SetScale(float scale) { _graphicInfo->scale = Vector2(scale, scale); }
	void SetAlpha(float alpha) { _graphicInfo->alpha = alpha; }

	UINT GetWidth() { return _graphicInfo->bitmap->GetPixelSize().width; }
	UINT GetHeight() { return _graphicInfo->bitmap->GetPixelSize().height; }

	int GetMaxFrameX() { return _graphicInfo->maxFrameX - 1; }
	int GetMaxFrameY() { return _graphicInfo->maxFrameY - 1; }
};
