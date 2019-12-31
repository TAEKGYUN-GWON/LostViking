#pragma once
#include"Component.h"

class Object;

class GraphicComponent : public Component
{
private:
	bool _isFrame;
	bool _isLoop;
	bool _isPlay;

	int _curFrameX;
	int _curFrameY;

	float _count;
	float _FPS;
	float _strokeWidth;

	string _imgKey;
	Graphic* _graphic;

	BRUSH_TYPE _color;
	PIVOT _pivot;

public:
	GraphicComponent();
	virtual void Init()
	{ 
		_color = BRUSH_TYPE::BLUE;
		_pivot = PIVOT::CENTER;
		_strokeWidth = 3.0f;
	}
	virtual void Init(BOOL isFrame = false, BOOL isLoop = false);

	virtual void Render();
	virtual void Update() override;

	inline void SetFrameY(int frameY) { _curFrameY = frameY; }
	inline void SetFPS(int time) { _FPS = 1.0f / time; }

	void Start();
	void Stop();
	void Pause();
	void Resume();

	void SetImgName(string key);
	inline void SetRectColor(BRUSH_TYPE color) { _color = color; }
	inline void SetStrokeWidth(float strokeWidth) { _strokeWidth = strokeWidth; }
	inline void SetPivot(PIVOT pivot) { _pivot = pivot; }

	bool IsFrameEnd();
	inline Graphic* GetGraphic() { return _graphic; }
};

