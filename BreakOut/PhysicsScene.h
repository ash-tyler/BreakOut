#pragma once
#include <list>
#include "VecLib\Vector2.h"
#include "PhysicsObject.h"

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();


	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	void debugScene();
	void update(float deltaTime);
	void draw();

	void checkForCollision();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	glm::vec2 getGravity() const { return m_gravity; }
	float getTimeStep() const { return m_timeStep; }


protected:
	std::list<PhysicsObject*> m_actors;
	glm::vec2 m_gravity;
	float m_timeStep;
};

