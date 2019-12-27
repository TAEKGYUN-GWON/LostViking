#pragma once
#include"Component.h"
class Object;

class GraphicComponent : public Component
{
private:
	bool _isFrame;
	int _curFrameX;
	int _curFrameY;
	int _count;
	int _FPS;
	string _imgKey;
public:
	GraphicComponent();

	virtual void Init(BOOL isFrame = false);

	virtual void Render();
	virtual void Update() override;

	inline void SetFrameY(int frameY) { _curFrameY = frameY; }
	inline void SetFPS(int time) { _FPS = time; }
	inline void SetImgName(string key) { _imgKey = key; }
	inline Graphic* GetGraphic(string key) { return GRAPHICMANAGER->FindImage(_imgKey); }
};

