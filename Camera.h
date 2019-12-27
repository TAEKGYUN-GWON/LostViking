#pragma once

#include "singletonBase.h"

class Camera : singletonBase<Camera>
{
private:
	D2D1_MATRIX_3X2_F _matrix;


public:
	HRESULT init();
	void release();

};

