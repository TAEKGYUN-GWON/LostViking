#pragma once
#include "Object.h"
#include "TransformComponent.h"
class PhysicsBodyComponent;
class Wall : public Object
{
private:
protected:
	PhysicsBodyComponent* _pBody;
	typedef Object super;
public:
	Wall();
	~Wall();
	virtual void Init();
	virtual void SetScale(Vector2 size) { _trans->scale = size; }
	virtual void SetScale(float x, float y) { _trans->scale.x = x; _trans->scale.y = y; }
	virtual void SetPos(Vector2 pos) { _trans->pos = pos; }
	virtual void SetPos(float x, float y) { _trans->pos.x = x; _trans->pos.y = y; }
	virtual Vector2 GetPos() { return _trans->pos; }
	virtual Vector2 GetScale() { return _trans->scale; }
	virtual void AddPbody();
	virtual PhysicsBodyComponent* getPbody() { return _pBody; }
};