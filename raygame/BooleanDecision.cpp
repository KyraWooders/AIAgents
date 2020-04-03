#include "BooleanDecision.h"

void BooleanDecision::makeDecision(Agent * agent, float deltaTime)
{
	if (testCondition(agent))
		m_a->makeDecision(agent, deltaTime);
	else
		m_b->makeDecision(agent, deltaTime);
}
