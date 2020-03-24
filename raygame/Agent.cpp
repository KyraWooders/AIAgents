#include "Agent.h"

void Agent::update(float deltaTime)
{
	//Set total force to zero
	//For each behavior in the behavior list
		//Call the behavior's update function
		//Add the returned value to the total force
	//Add total force times delta time to velocity
	//Add velocity times delta time to position
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, BLUE);
}

void Agent::addBehavior(Behavior* behavior)
{
	//Add the Behavior to the Behavior list
}
