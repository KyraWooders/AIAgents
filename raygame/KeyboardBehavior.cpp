#include "KeyboardBehavior.h"

Vector2 KeyboardBehavior::update(Agent* agent, float deltaTime)
{
	//find the directon
	Vector2 direction = { 0.0f,0.0f };

	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))      direction.y = -500.0f;
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))    direction.y = 500.0f;
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))    direction.x = -500.0f;
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))   direction.x = 500.0f;

	//normalize in case of diagonal
	direction = direction.normalize();

	//multipty the diretion by the desired speed
	Vector2 force = direction * agent->getSpeed();

	//subtract the agent's current velocity from the result to get the force we need to apply
	force = force - agent->getVelocity();

	return force;
}
