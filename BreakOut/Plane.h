#pragma once
#include "PhysicsObject.h"
class Plane :
	public PhysicsObject
{
public:
	Plane(ShapeType shapeTypeID);
	~Plane();
};
