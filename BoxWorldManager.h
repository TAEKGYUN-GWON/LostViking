#pragma once
class BoxWorldManager : public singletonBase<BoxWorldManager>
{
private:
	b2World* _world;
public:
	BoxWorldManager();
	~BoxWorldManager();
	virtual void Release();
	void RemoveBody(b2Body* body);
	void SetWorld();
	inline b2World* GetWorld() { return _world; }
};

