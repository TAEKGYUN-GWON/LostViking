#include "stdafx.h"
#include "GraphicComponent.h"
#include "TransformComponent.h"
#include "Object.h"
#include "PhysicsBodyComponent.h"

GraphicComponent::GraphicComponent()
{
	_name = "GraphicComponent";

	_color = Brush_type::BLUE;
	_pivot = PIVOT::CENTER;
	_strokeWidth = 3.0f;
}

void GraphicComponent::Init(BOOL isFrame, BOOL isLoop)
{
	_imgKey.clear();
	_isFrame = isFrame;
	_isLoop = isLoop;
	_isPlay = false;

	_curFrameX = _curFrameY = 0;
	_count = 0.0f;
	_FPS = 1.0f / 1;
}

void GraphicComponent::Render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		PhysicsBodyComponent* a = _object->GetComponent<PhysicsBodyComponent>();

		if (a != nullptr)
			GRAPHICMANAGER->DrawRect(_object->GetTrans()->GetPos(), _object->GetTrans()->GetScale(), a->GetBody()->GetAngle() * DEGREE, _color, _pivot, _strokeWidth);
		else
			GRAPHICMANAGER->DrawRect(_object->GetTrans()->GetPos(), _object->GetTrans()->GetScale(), _object->GetTrans()->GetRotateRadian(), _color, _pivot, _strokeWidth);
	}

	if (_imgKey.empty()) return;

	if (_isFrame)
	{
		if (_isPlay)
		{
			_count += TIMEMANAGER->getElapsedTime() * 5;

			if (_count >= _FPS)
			{
				_count -= _FPS;
				_curFrameX++;
				if (_curFrameX > _maxFrameX)
				{
					if (_isLoop) _curFrameX = 0;
					else
					{
						_curFrameX--;
						_isPlay = false;
					}
				}
			}
		}
		GRAPHICMANAGER->DrawFrameImage(_imgKey, _object->GetTrans()->GetPos(), _curFrameX, _curFrameY, _pivot);
	}
	else
	{
		GRAPHICMANAGER->DrawImage(_imgKey, _object->GetTrans()->GetPos(), _pivot);
	}
}

void GraphicComponent::Update()
{
	return;
}

void GraphicComponent::Start()
{
	_isPlay = true;
	_curFrameX = 0;
	_graphic->SetCurrentFrameX(_curFrameX);
}

void GraphicComponent::Stop()
{
	_isPlay = false;
	_curFrameX = 0;
	_graphic->SetCurrentFrameX(_curFrameX);
}

void GraphicComponent::Pause()
{
	_isPlay = false;
}

void GraphicComponent::Resume()
{
	_isPlay = true;
}

void GraphicComponent::SetImgName(string key)
{
	 _imgKey = key; 
	 _graphic = GRAPHICMANAGER->FindImage(_imgKey); 
	 _maxFrameX = _graphic->GetMaxFrameX();

	 if(_isFrame) _isPlay = true;
}

bool GraphicComponent::IsFrameEnd()
{
	if (_curFrameX >= _maxFrameX)
	{
		_curFrameX = _maxFrameX;
		return true;
	}
	return false;
}

