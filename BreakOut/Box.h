#pragma once
#include "RigidBody.h"
class Box :
	public RigidBody
{
public:
	Box(ShapeType shapeTypeID);
	~Box();
};
