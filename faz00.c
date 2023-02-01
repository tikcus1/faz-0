/*******************************************************************************************
*
*   raylib [textures] example - Texture loading and drawing
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "BOARD GAME");
    Vector2 ballPosition = { (float)screenWidth/screenWidth + 110, (float)screenHeight - 35 };
    float rotation = 0.0f;
    SetTargetFPS(60);   

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D texture = LoadTexture("resources/BORD_B.png");        // Texture loading
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        rotation += 0.2f;
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);

            //DrawText("this IS a texture!", 360, 370, 10, GRAY);
            ClearBackground(RAYWHITE);

            //DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 20, MAROON);
        
            DrawCircle(110, 427, 20, PINK);
            DrawCircle(screenWidth - 90, 27, 20, SKYBLUE);
            DrawCircle(screenWidth - 80, 27, 20, DARKBLUE);
            //DrawCircleGradient(screenWidth/5, 220, 60, GREEN, SKYBLUE);
            //DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
