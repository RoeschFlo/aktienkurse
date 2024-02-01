#include "../include/eingabe_feld.h"

Gui_Namespace::Eingabe_feld::Eingabe_feld(int width, int height, 
    int pos_x, int pos_y, std::string label):Rechteck(width, 
        height,pos_x,pos_y,label){

            eingabe_m="";
            name_m[0]= '\0';
            rect_box_m ={(float)pos_x_m, (float)pos_y_m,
                (float)width_m, (float)height_m};
            mouseOnText_m=false;
            letterCount_m=0;
            framesCounter_m=0;
        };

void Gui_Namespace::Eingabe_feld::draw(){
    //Text wird gerendert
    raylib_namespace::DrawText("PLACE MOUSE OVER INPUT BOX!", pos_x_m, 
        pos_y_m + 40, 20, raylib_namespace::BLACK );
    //Eingabe Box an sich wird gerendert
    raylib_namespace::DrawRectangleRec(rect_box_m, 
        raylib_namespace::LIGHTGRAY);
    
    if (mouseOnText_m) 
    {    //Boxrand wird rot hevorgehoben wenn Maus auf Text
        raylib_namespace::DrawRectangleLines(
            (int)rect_box_m.x, (int)rect_box_m.y, (int)rect_box_m.width, 
            (int)rect_box_m.height, raylib_namespace::RED);
    }
    else 
    {   //Wenn maus nicht auf Text -> Boxrand Grau
        raylib_namespace::DrawRectangleLines((int)rect_box_m.x, 
            (int)rect_box_m.y, (int)rect_box_m.width, (int)rect_box_m.height, 
            raylib_namespace::DARKGRAY);
    }
    // Die eingegebene Info an sich wird gerendert
    raylib_namespace::DrawText(name_m, (int)rect_box_m.x + 5, 
        (int)rect_box_m.y + 8, 40, raylib_namespace::MAROON);

    // Anzahl der eingegebenen Buchstaben wird rerendert
    raylib_namespace::DrawText(raylib_namespace::TextFormat(
        "INPUT CHARS: %i/%i", letterCount_m, MAX_INPUT_CHARS), pos_x_m, 
        pos_y_m-20, 20, raylib_namespace::DARKGRAY);

    if (mouseOnText_m)
    {
        if (letterCount_m < MAX_INPUT_CHARS)       
        {
            // Draw blinking underscore char
            if (((framesCounter_m/20)%2) == 0) DrawText("_", (int)rect_box_m.x +
                8 + raylib_namespace::MeasureText(name_m, 40), (int)rect_box_m.y +
                12, 40, raylib_namespace::MAROON);
            }
            // Wenn die Anzahl der max. möglichen Chars erreicht wurde
             else raylib_namespace::DrawText("Press BACKSPACE to delete chars...",
                (int)rect_box_m.x,(int)rect_box_m.y-40, 20, raylib_namespace::BLACK );
    }    
}

void Gui_Namespace::Eingabe_feld::update_m(){
    if (raylib_namespace::CheckCollisionPointRec(
            raylib_namespace::GetMousePosition(), rect_box_m)) mouseOnText_m = true;
        else mouseOnText_m = false;

    if (mouseOnText_m)
    {
        // Set the window's cursor to the I-Beam
        raylib_namespace::SetMouseCursor(raylib_namespace::MOUSE_CURSOR_IBEAM);
        
        // Get char pressed (unicode character) on the queue
        int key = raylib_namespace::GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount_m < MAX_INPUT_CHARS))
            {
                name_m[letterCount_m] = (char)key;
                name_m[letterCount_m+1] = '\0'; // Add null terminator at the end of the string.
                letterCount_m++;
            }

            key = raylib_namespace::GetCharPressed();  // Check next character in the queue
        }
        if (raylib_namespace::IsKeyPressed(raylib_namespace::KEY_BACKSPACE))
            {
                letterCount_m--;
                if (letterCount_m < 0) letterCount_m = 0;
                name_m[letterCount_m] = '\0';
            }
    }
    else raylib_namespace::SetMouseCursor(raylib_namespace::MOUSE_CURSOR_DEFAULT);

    if  (mouseOnText_m) framesCounter_m++;
    else framesCounter_m = 0;
   
};

std::string Gui_Namespace::Eingabe_feld::get_eingabe_m(){
    return name_m;
};
