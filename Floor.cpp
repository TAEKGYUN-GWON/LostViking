#include "stdafx.h"
#include "Floor.h"
#include "GraphicComponent.h"

Floor::Floor()
{
	_name = "Floor";

	_graphic->SetRectColor(BRUSH_TYPE::GREEN);
}


Floor::~Floor()
{
}

void Floor::Init()
{
}
