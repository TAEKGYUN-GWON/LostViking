#pragma once
class TransformComponent;

class Object
{
protected:
	TransformComponent *_trans;
	string _ObjName;
	bool _isActive;
public:
	Object() {};
	~Object() {};
	virtual HRESULT Init() {};
	virtual void Interaction() {};
	virtual void Interaction2() {};
	virtual void Update() {};
	virtual inline TransformComponent * GetTrans() { return _trans; }
};