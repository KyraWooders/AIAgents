#pragma once
#include "Decision.h"
#include "Condition.h"

class BooleanDecision : public Decision
{
public:
	virtual void makeDecision(Agent* agent, float deltaTime);

private:
	Decision* a;
	Decision* b;

protected:
	virtual bool testCondition(Agent* agent) { return false; }
};

