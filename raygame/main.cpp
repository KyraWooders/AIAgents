/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "Behavior.h"
#include "KeyboardBehavior.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"
#include "PursuitBehavior.h"
#include "EvadeBehavior.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	Agent* player = new Agent();
	player->setPosition({ 600.0f, 600.0f });
	player->setSpeed(500.0f);
	player->setColor(RED);
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);

	Agent* seeker = new Agent();
	seeker->setPosition({ 500.0f, 500.0f });
	seeker->setSpeed(250.0f);
	seeker->setColor(ORANGE);
	SeekBehavior* seekBehavior = new SeekBehavior();
	seekBehavior->setTarget(player);	
	seeker->addBehavior(seekBehavior);

	Agent* fleer = new Agent();
	fleer->setPosition({ 400.0f, 400.0f });
	fleer->setSpeed(20.0f);
	fleer->setColor(SKYBLUE);
	FleeBehavior* fleeBehavior = new FleeBehavior();
	fleeBehavior->setTarget(player);
	fleer->addBehavior(fleeBehavior);

	Agent* wander = new Agent();
	wander->setPosition({ 900.0f, 900.0f });
	wander->setSpeed(80.0f);
	wander->setColor(LIME);
	WanderBehavior* wanderBehavior = new WanderBehavior();
	wander->addBehavior(fleeBehavior);

	Agent* pursuer = new Agent();
	pursuer->setPosition({ 500.0f, 400.0f });
	pursuer->setSpeed(250.0f);
	pursuer->setColor(DARKBLUE);
	PursuitBehavior* pursuitBehavior = new PursuitBehavior();
	pursuitBehavior->setTarget(player);
	pursuer->addBehavior(pursuitBehavior);

	Agent* evader = new Agent();
	evader->setPosition({ 500.0f, 400.0f });
	evader->setSpeed(250.0f);
	evader->setColor(DARKGREEN);
	EvadeBehavior* evadeBehavior = new EvadeBehavior();
	evadeBehavior->setTarget(player);
	evader->addBehavior(evadeBehavior);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		player->update(GetFrameTime());
		seeker->update(GetFrameTime());
		fleer->update(GetFrameTime());
		wander->update(GetFrameTime());
		pursuer->update(GetFrameTime());
		evader->update(GetFrameTime());
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(MAROON);
						
		player->draw();
		seeker->draw();
		fleer->draw();
		wander->draw();
		pursuer->draw();
		evader->draw();
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}