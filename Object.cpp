#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	_trans = AddComponent<TransformComponent>();
	_trans->SetPos(Vector2::zero);
	_trans->SetScale(Vector2(1,1));
	_graphic = AddComponent<GraphicComponent>();
}

void Object::Update()
{
	if (!_isActive)return;
	for (int i = 0; i<_components.size();i++)
		_components[i]->Update();

}

void Object::Release()
{
	for (int i = _components.size()-1; i >= 0; i--)
	{
		_components[i]->Release();
	}
	delete this;
}

void Object::Render()
{
	_graphic->Render();
}

void Object::RemoveComponent(Component * component)
{
	for (auto iter = _components.begin(); iter != _components.end(); iter++)
	{
		if (component != *iter)
			continue;
		_components.erase(iter);
		delete(component);
		return;
	}
}
