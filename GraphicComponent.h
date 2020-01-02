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

	int _maxFrameX;

	float _count;
	float _FPS;
	float _strokeWidth;

	string _imgKey;
	Graphic* _graphic;

	Brush_type::Enum _color;
	PIVOT _pivot;

public:
	GraphicComponent();
	virtual void Init(BOOL isFrame = false, BOOL isLoop = false);

	virtual void Render();
	virtual void Update() override;

	inline void SetFrameX(int frameX) { _curFrameX = frameX; }
	inline void SetFrameY(int frameY) { _curFrameY = frameY; }
	inline void SetFPS(float time) { _FPS = 1.0f / time; }
	inline string GetImgKey() { return _imgKey; }
	void Start();
	void Stop();
	void Pause();
	void Resume();

	void SetImgName(string key);
	void SetMaxFrameX(int maxFrameX) { _maxFrameX = maxFrameX - 1; }
	inline void SetRectColor(Brush_type::Enum color) { _color = color; }
	inline void SetStrokeWidth(float strokeWidth) { _strokeWidth = strokeWidth; }
	inline void SetPivot(PIVOT pivot) { _pivot = pivot; }

	bool IsFrameEnd();
	inline Graphic* GetGraphic() { return _graphic; }
};

