#pragma once
//=========================================
// ## 2019.11.15 ## Image ##
//=========================================

#include "animation.h"

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,
		LOAD_FILE,
		LOAD_EMPTY,
		LOAD_END
	};


	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		float x;			//�̹��� �ѷ��� ���� X(left)
		float y;			//�̹��� �ѷ��� ���� Y(top)
		int width;			//�̹��� ��ü ����ũ��
		int height;			//�̹��� ��ü ����ũ��
		int currentFrameX;	//���� ������ ���ι�ȣ (X��)
		int currentFrameY;	//���� ������ ���ι�ȣ (Y��)
		int maxFrameX;		//�ִ� ������ ��ȣ ����
		int maxFrameY;		//�ִ� ������ ��ȣ ����
		int frameWidth;		//�� �������� ����ũ��
		int frameHeight;	//�� �������� ����ũ��

		BYTE loadType;

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = 0;
			y = 0;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;
private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
	BOOL			_trans;
	COLORREF		_transColor;

	BLENDFUNCTION _blendFunc;	//���ĺ��� ���� �Լ���
	LPIMAGE_INFO  _blendImage;	//���ĺ��� ó���� �̹���
public:
	image();
	~image();

	HRESULT init(int width, int height);
	HRESULT init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	void release();

	void setTransColor(BOOL trans, COLORREF transColor);

	//�����Լ� (�ѷ��� DC)
	void render(HDC hdc);
	//�����Լ� (�ѷ���DC, �Ѹ���ǥ(left), �Ѹ���ǥ(top)
	void render(HDC hdc, int destX, int destY);
	//�����Լ� �ѷ���DC, �Ѹ���ǥX(left),�Ѹ���ǥY(top), �߶�ð�X(left), �߶�ð�Y(top), �߶�� ����ũ��, �߶�� ����ũ��
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//�̹��� ������ ����(�ѷ���DC, �ѷ���left,  �ѷ���top)
	void frameRender(HDC hdc, int destX, int destY);
	//�̹��� ������ ����(�ѷ���DC, �ѷ���left, �ѷ���top, ������X��ȣ, ������Y��ȣ
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);

	//���� ���� (�ѷ���DC, ���İ�(����) 0 ~ 255)
	void alphaRender(HDC hdc, BYTE alpha);
	//���� ����(�ѷ���DC, left, top, ���İ� 0 ~ 255)
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);

	void scaleRender(HDC, int destX, int destY, int scaleX, int scaleY);

	void aniRender(HDC hdc, int destX, int destY, animation* ani);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	//===================================
	// ## �̹��� ���� ������, ������ ##
	//===================================

	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX() { return _imageInfo->x; }

	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY() { return _imageInfo->y; }

	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float getCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ?
			_imageInfo->x + (_imageInfo->width / 2) :
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float getCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ?
			_imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);

	}

	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;

		//�����ӹ�ȣ�� �ִ������ӹ�ȣ�� �Ѿ�� ������ ���������� ����
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}

	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;

		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline int getFrameY() { return _imageInfo->currentFrameY; }

	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight; }

};

