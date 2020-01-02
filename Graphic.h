#pragma once

enum PIVOT
{
	LEFT_TOP,
	CENTER,
	BOTTOM,
	TOP,
};

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
		int							curFrameX;
		int							curFrameY;
		string						imgKey;
		wstring						imgPath;

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
			curFrameX = 0;
			curFrameY = 0;
			//imgKey = nullptr;
			//imgPath = nullptr;
		}
	}GRAPHIC_INFO, *LPGRAPHIC_INFO;

private:
	LPGRAPHIC_INFO					_graphicInfo;

	vector<WICRect>					_vFrameRect;
	vector<WICRect>::iterator		_viFrameRect;

public:
	Graphic() {};
	~Graphic() {};

	HRESULT Init(ID2D1Bitmap* bitmap, string key, wstring path);
	HRESULT Init(ID2D1Bitmap* bitmap, string key, wstring path, int maxFrameX, int maxFrameY);
	void Release();
	//void Render(float x, float y);
	void Render(float x, float y, PIVOT pivot = PIVOT::CENTER);
	void Render(Vector2 pos, PIVOT pivot = PIVOT::CENTER);
	void RenderUI(float x, float y, PIVOT pivot = PIVOT::CENTER);
	void RenderUI(Vector2 pos, PIVOT pivot = PIVOT::CENTER);
	void FrameRender(float x, float y, int curFrameX, int curFrameY, PIVOT pivot = PIVOT::CENTER);
	void FrameRender(Vector2 pos, int curFrameX, int curFrameY, PIVOT pivot = PIVOT::CENTER);
	
	void SetSize(Vector2 size) { _graphicInfo->size = size; }
	void SetAngle(float angle) { _graphicInfo->angle = angle; }
	void SetScale(Vector2 scale) { _graphicInfo->scale = scale; }
	void SetAlpha(float alpha) { _graphicInfo->alpha = alpha; }

	void SetCurrentFrameX(int frame) { _graphicInfo->curFrameX = frame; }
	void SetCurrentFrameY(int frame) { _graphicInfo->curFrameY = frame; }

	UINT GetWidth() { return _graphicInfo->bitmap->GetPixelSize().width; }
	UINT GetHeight() { return _graphicInfo->bitmap->GetPixelSize().height; }
	Vector2 GetFrameSize(int frame) { return Vector2(_vFrameRect[frame].Width, _vFrameRect[frame].Height); }

	int GetMaxFrameX() { return _graphicInfo->maxFrameX - 1; }
	int GetMaxFrameY() { return _graphicInfo->maxFrameY - 1; }

	int GetCurrentFrameX() { return _graphicInfo->curFrameX; }
	int GetCurrentFrameY() { return _graphicInfo->curFrameY; }

	int GetFrameWidth() { return _graphicInfo->frameWidth; }
	int GetFrameHeight() { return _graphicInfo->frameHeight; }

	LPGRAPHIC_INFO GetGraphicInfo() { return _graphicInfo; }

	string GetImageKey() { return _graphicInfo->imgKey; }
};
