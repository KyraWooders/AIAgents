#pragma once
#include "Behavior.h"

class SeekBehavior : public Behavior
{
public:
	SeekBehavior() {}
	virtual ~SeekBehavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	//the target they will be seeking
	void setTarget(Agent* agent) { m_Target = agent; }

private:
	Agent* m_Target = nullptr;
};

