#include "stdafx.h"
#include "Object.h"


void Object::RemoveComponent(Component * component)
{
	for (auto iter = _components.begin(); iter != _components.end(); iter++)
	{
		_components.erase(iter);
		delete(component);
		return;
	
	}
}
