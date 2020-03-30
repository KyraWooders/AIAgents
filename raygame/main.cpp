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
#include "FSM.h"

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

	Agent* enemy = new Agent();
	enemy->setPosition(Vector2{ 800.0f, 450.0f });
	enemy->setSpeed(250.0f);
	enemy->setColor(BROWN);
	FSM* enemyFSM = new FSM();



	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		player->update(GetFrameTime());
		
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(MAROON);
						
		player->draw();
		
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}