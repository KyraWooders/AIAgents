#pragma once
#include "Behavior.h"

class WanderBehavior : public Behavior
{
public:
	WanderBehavior() {}
	virtual ~WanderBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
};

