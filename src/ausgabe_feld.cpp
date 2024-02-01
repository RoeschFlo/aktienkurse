#include "../include/ausgabe_feld.h"

Gui_Namespace::Ausgabe_feld::Ausgabe_feld(int width, int height,
    int pos_x, int pos_y, std::string label):Rechteck(width,
        height, pos_x, pos_y, label){
            rect_box_m ={(float)pos_x_m, (float)pos_y_m,
                (float)width_m, (float)height_m};
        };

void Gui_Namespace::Ausgabe_feld::draw(){
    raylib_namespace::DrawRectangleRec(rect_box_m, 
        raylib_namespace::LIGHTGRAY);
    
    raylib_namespace::DrawText(label_m.c_str(), (int)rect_box_m.x + 5, 
        (int)rect_box_m.y + 8, 40, raylib_namespace::MAROON);
}

void Gui_Namespace::Ausgabe_feld::update_m(const std::string& ref_to_DB)
{
    if (ref_to_DB != label_m){
        label_m = ref_to_DB;
    }
    
}