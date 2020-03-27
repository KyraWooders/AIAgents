#include "WanderBehavior.h"
#include <cstdlib>

Vector2 WanderBehavior::update(Agent * agent, float deltaTime)
{
	//randomize the 'target' position
	auto randVec = []()
	{
		float randX = (float)rand() - ((float)RAND_MAX / 2);
		float randY = (float)rand() - ((float)RAND_MAX / 2);
		return Vector2{ randX, randY };
	};

	//start with a random target on the edge of the sphere with a set radius around the agent
	Vector2 targetPos = randVec().normalize() * m_radius;

	//add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos += randVec().normalize() * m_jitter;

	//bring the target back to the radius of the sphere by normalising it and scaling by the radius
	targetPos = targetPos.normalize() * m_radius;

	//add the agent's heading, multiplied by the distance, to the target
	Vector2 heading = agent->getVelocity().normalize();
	targetPos += heading * m_offset;

	//add the previous target
	targetPos += m_prevTarget;

	//store previous target
	m_prevTarget.x = targetPos.x;
	m_prevTarget.y = targetPos.y;

	//seek target
	Vector2 pos = agent->getPosition();

	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	Vector2 force = direction * agent->getSpeed();
	//Subtract the agent's current velocity from the result to get the force we need to apply
	force = force - agent->getVelocity();

	//Return the force
	return force;
	
}
