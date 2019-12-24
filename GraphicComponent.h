#pragma once
class Object;
class GraphicComponent
{
private:
	Object *_object;

public:
	GraphicComponent(Object *object);
	~GraphicComponent();
};

