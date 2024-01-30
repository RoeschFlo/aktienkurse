
#include "../include/my_includes.h"
#include "../include/gui.h"
/*Die Hierachie ist:
Es gibt eine GUI mit einer Seite, welche mehrere Bedienelemente haben können
Mehrer Seiten kommt später noch*/


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Gui_Namespace::prt_table prt_table_obj;
    Gui_Namespace::Gui myGui;
     printf("MySQL client version: %s\n", mysql_get_client_info());

    raylib_namespace::InitWindow(2000,1600,"42");

    raylib_namespace::SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
   


    // Main game loop
    while (!raylib_namespace::WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        myGui.update_all();
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        raylib_namespace::BeginDrawing();

            raylib_namespace::ClearBackground(raylib_namespace::RAYWHITE);

            myGui.draw_all();
            
        raylib_namespace::EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    raylib_namespace::CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

