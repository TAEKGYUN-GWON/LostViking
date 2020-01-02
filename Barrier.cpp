#include "stdafx.h"
#include "Barrier.h"

#include "GraphicComponent.h"

Barrier::Barrier()
{
	_name = "Barrier";

	_graphic->SetRectColor(Brush_type::RED);
}


Barrier::~Barrier()
{
}

void Barrier::Init()
{

}
