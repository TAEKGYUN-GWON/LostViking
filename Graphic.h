#pragma once

class Graphic
{
public:
	struct tagGraphicInfo
	{
		string key;
		wstring path;
	};

private:
	static ID2D1HwndRenderTarget* _RT;

	ID2D1Bitmap*		_bitmap;
	Vector2				_size;
	Vector2				_scale;
	float				_angle;
	float				_alpha;
	tagGraphicInfo		_graphicInfo;

public:
	Graphic() { _bitmap = nullptr; };
	~Graphic() {};

	HRESULT Init(ID2D1Bitmap* bitmap, tagGraphicInfo graphicInfo);
	void Release();
	void Render(float x, float y);
	
	void SetSize(Vector2 size) { _size = size; }
	void SetAngle(float angle) { _angle = angle; }
	void SetScale(float scale) { _scale = Vector2(scale, scale); }
	void SetAlpha(float alpha) { _alpha = alpha; }

	UINT GetWidth() { return _bitmap->GetPixelSize().width; }
	UINT GetHeight() { return _bitmap->GetPixelSize().height; }

	tagGraphicInfo GetGraphicInfo() { return _graphicInfo; }

	static void SetRenderTarget(ID2D1HwndRenderTarget* rt) 
	{
		_RT = rt; 
	}
};
