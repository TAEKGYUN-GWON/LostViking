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
	string _imgKey;
	Graphic* _graphic;

public:
	GraphicComponent();

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

	bool IsFrameEnd();
	inline Graphic* GetGraphic() { return _graphic; }
};

