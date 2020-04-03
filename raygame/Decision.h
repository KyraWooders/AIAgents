#pragma once
#include "Agent.h"

class Decision
{
public:
	Decision() {}
	virtual ~Decision() {}

	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};

