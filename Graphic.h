#pragma once

class Graphic
{
private:
	//ID2D1Bitmap*		_bitmap;
	Vector2				_size;
	Vector2				_scale;
	float				_angle;

public:
	Graphic();
	~Graphic();

	HRESULT Init(/*ID2D1Bitmap* bitmap*/);
	void Release();
};
