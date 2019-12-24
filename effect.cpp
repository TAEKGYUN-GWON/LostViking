#include "stdafx.h"
#include "effect.h"
#include "animation.h"


effect::effect()
	: _effectImage(NULL),
	_effectAnimation(NULL),
	_isRunning(false),
	_x(0), _y(0)
{
}


effect::~effect()
{
}

HRESULT effect::init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	//����Ʈ �̹����� ������ ���и� �����
	if (!effectImage) return E_FAIL;

	_isRunning = false;
	_effectImage = effectImage;
	_elapsedTime = elapsedTime;

	if (!_effectAnimation) _effectAnimation = new animation;

	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlayFrame(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();

	return S_OK;
}

void effect::release()
{
	_effectImage = NULL;
	SAFE_DELETE(_effectAnimation);
}

void effect::update()
{
	//����Ʈ �ִϸ��̼� ���� ������ false�� ������������
	if (!_isRunning) return;

	_effectAnimation->frameUpdate(_elapsedTime);

	//���� �ִϸ��̼� �����ȣ�� false�� ����Ʈ�� ����
	if (!_effectAnimation->isPlay()) killEffect();

}

void effect::render()
{

	if (!_isRunning) return;

	_effectImage->aniRender(getMemDC(), _x, _y, _effectAnimation);

}

void effect::startEffect(int x, int y)
{
	if (!_effectImage || !_effectAnimation) return;

	//�ϴ� �߾Ӱ�����... ��ž���� ��ž���� ��...
	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;

	_effectAnimation->start();

}

void effect::killEffect()
{
	_isRunning = false;
}
