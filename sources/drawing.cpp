#include "drawing.h"

void drawing_interface::draw() {
    

    ClearBackground(RAYWHITE);

   

    const char* text = "OMG! IT WORKS!";
    const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
    DrawText(text, 100,100, 20, BLACK);

    EndDrawing();
}