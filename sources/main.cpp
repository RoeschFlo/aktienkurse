#include "global_stuff.h"
#include "drawing.h"
#include "speicher.h"
#include "button.h"




int main(void)
{
    
    int zahl = 0;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    drawing_interface page_1_obj;
    
    Vector2 mouse_position = { -1.0f,-1.0f }; 
    save_button save_button_obj(200, 100, 300, 400, "Speichern");
    
    while (!WindowShouldClose())
    {
        mouse_position = GetMousePosition();
        //page_1.update();
        page_1_obj.draw();
        save_button_obj.draw();
    }

    CloseWindow();

    return 0;
}
