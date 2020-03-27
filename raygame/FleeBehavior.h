#pragma once
#include "Behavior.h"

class FleeBehavior : public Behavior
{
public:
	FleeBehavior() {}
	virtual ~FleeBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	//the target they will be fleeing from
	void setTarget(Agent* agent) { m_Target = agent; }

private:
	Agent* m_Target = nullptr;
};

