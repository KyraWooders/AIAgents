#pragma once
#include "raylib.h"
#include <vector>

class Behavior;

class Agent
{
public:
	Agent() {}
	virtual ~Agent() {}
	
	virtual void update(float deltaTime);

	virtual void draw();

	void addBehavior(Behavior behavior);

	void setPosition(Vector2 position) { m_Position = position; }
	Vector2 getPosition() { return m_Position; }
	void setVelocity(Vector2 velocity) { m_Velocity = velocity; }
	Vector2 getVelocity() { return m_Velocity; }

protected:
	std::vector<Behavior*>m_BehaviorList;

	Vector2 m_Position = { 0,0 };
	Vector2 m_Velocity = { 0,0 };
};

