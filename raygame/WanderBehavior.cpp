#include "WanderBehavior.h"
#include <cstdlib>

Vector2 WanderBehavior::update(Agent * agent, float deltaTime)
{
	//start with a random target on the edge of the sphere with a set radius around the agent
	float randRange = ((float)RAND_MAX) / 2;
	Vector2 targetPos = Vector2{ (float)rand() - randRange, (float)rand() - randRange }.normalize() * m_radius;

	//add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos += Vector2{ (float)rand() - randRange, (float)rand() - randRange }.normalize() * m_jitter;

	//bring the target back to the radius of the sphere by normalising it and scaling by the radius
	targetPos = targetPos.normalize() * m_radius;

	//add the agent's heading, multiplied by the distance, to the target
	Vector2 heading = agent->getVelocity().normalize();

	//seek target
	Vector2 pos = agent->getPosition();

	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	direction = direction * 500;
	//Subtract the agent's current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->getVelocity();

	//Return the force
	return force;
	
}
