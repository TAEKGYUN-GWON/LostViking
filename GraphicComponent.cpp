#include "stdafx.h"
#include "GraphicComponent.h"
#include "TransformComponent.h"
#include "Object.h"
GraphicComponent::GraphicComponent()
{
	_name = "GraphicComponent";

}
void GraphicComponent::Init(BOOL isFrame)
{
	_imgKey.clear();
	_isFrame = isFrame;
	_count = _curFrameX = _curFrameY = 0;
	_FPS = 7;
}

void GraphicComponent::Render()
{
	//if (KEYMANAGER->isToggleKey(VK_F1))
	//{
		GRAPHICMANAGER->DrawCenterRect(_object->GetTrans()->GetPos(), _object->GetTrans()->GetScale(),
			BRUSH_TYPE::BLUE);
	//}

	if (_isFrame)
	{
		_count++;
		if (_count > _FPS)
		{
			_curFrameX++;
			if (_curFrameX > GRAPHICMANAGER->FindImage(_imgKey)->GetMaxFrameX()) _curFrameX = 0;
			_count = 0;
		}
		if (_imgKey.empty())return;
		GRAPHICMANAGER->DrawFrameImage(_imgKey, _object->GetTrans()->GetPos(), _curFrameX, _curFrameY);
	}
	else
	{
		if (_imgKey.empty())return;
		GRAPHICMANAGER->DrawImage(_imgKey, _object->GetTrans()->GetPos());
	}
}

void GraphicComponent::Update()
{
	return;
}

