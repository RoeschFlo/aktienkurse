#include <iostream>
#include "../include/my_includes.h"
#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char **argv)
// {

//   printf("MySQL client version: %s\n", mysql_get_client_info());

//   exit(0);
//   return 42;
// }

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    Cppwrapper::InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Cppwrapper::SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!Cppwrapper::WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        Cppwrapper::BeginDrawing();

            Cppwrapper::ClearBackground(Cppwrapper::RAYWHITE);

            Cppwrapper::DrawText("Congrats! You created your first window!", 190, 200, 20,
                     Cppwrapper::LIGHTGRAY);

        Cppwrapper::EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    Cppwrapper::CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

