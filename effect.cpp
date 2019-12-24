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
	//이펙트 이미지가 없으면 실패를 띄워라
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
	//이펙트 애니메이션 실행 변수가 false면 실행하지마라
	if (!_isRunning) return;

	_effectAnimation->frameUpdate(_elapsedTime);

	//만약 애니메이션 재생신호가 false면 이펙트를 꺼라
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

	//일단 중앙값으로... 레탑들은 레탑으로 해...
	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;

	_effectAnimation->start();

}

void effect::killEffect()
{
	_isRunning = false;
}
