#include "FSM.h"

FSM::~FSM()
{
	for (State * s : m_states)
	{
		delete s;
	}		
	for (Transition* t : m_transitions)
	{
		delete t;
	}
	for (Condition* c : m_conditions)
	{
		delete c;
	}
}

Vector2 FSM::update(Agent * agent, float deltaTime)
{
	//stop if we have no current state
	if (m_currentState == nullptr)
	{
		return Vector2{ 0.0f,0.0f };
	}

	//check if a transition has been triggered
	Transition* transition = m_currentState->getTriggeredTransition(agent);

	//if there is a transition, change states
	if (transition != nullptr)
	{
		m_currentState->exit(agent);
		m_currentState = transition->getTargetState();
		m_currentState->init(agent);
	}

	//update the current state
	m_currentState->update(agent, deltaTime);
	return Vector2{ 0.0f,0.0f };
}
