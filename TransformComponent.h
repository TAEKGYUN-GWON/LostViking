#pragma once
class Object;

class TransformComponent
{
private:
	Object *_object;
	Vector2 _pos;
	Vector2 _scale;
public:
	TransformComponent(Object* object);
	~TransformComponent();
	void SetScale(Vector2 scale);
	void Update();
	inline Vector2 GetPos() { return _pos; }
	inline Vector2 GetScale() { return _scale; }
	inline void SetPos(Vector2 pos) { _pos = pos; }
};

