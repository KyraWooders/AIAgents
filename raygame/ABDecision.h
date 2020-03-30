#pragma once
#include "Decision.h"
#include "Condition.h"

class ABDecision : public Decision
{
public:
	ABDecision();
	ABDecision(Decision* child1, Decision* child2);

	void makeDecision(Agent* agent, float deltaTime) override;

private:
	Decision* A;
	Decision* B;

	virtual bool checkCondition(Agent* agent, float deltaTime);
};

