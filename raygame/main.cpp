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
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);

	Agent* enemy = new Agent();
	enemy->setPosition({ 500.0f, 500.0f });
	SeekBehavior* seekBehavior = new SeekBehavior();	
	WanderBehavior* wanderBehavior = new WanderBehavior();
	seekBehavior->setTarget(player);	
	enemy->addBehavior(seekBehavior);

	/*Agent* fam = new Agent();
	fam->setPosition({ 400.0f, 400.0f });
	FleeBehavior* fleeBehavior = new FleeBehavior();
	fleeBehavior->setTarget(player);
	fam->addBehavior(fleeBehavior);*/

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		player->update(GetFrameTime());
		enemy->update(GetFrameTime());
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(MAROON);

		
		//fam->draw();
		player->draw();
		enemy->draw();
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}