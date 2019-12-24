#pragma once

class Graphic
{
private:
	ID2D1Bitmap*		_bitmap;

public:
	Graphic();
	~Graphic();

	HRESULT Init();
	void release();
};
