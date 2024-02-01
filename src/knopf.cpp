#include "../include/knopf.h"

Gui_Namespace::Knopf::Knopf(int width, int height, int pos_x, 
                            int pos_y, std::string label):
                            Rechteck(width, height,pos_x,pos_y,
                            label){};

bool Gui_Namespace::Knopf::isHovering_m(){
    return raylib_namespace::CheckCollisionPointRec
    (
        raylib_namespace::GetMousePosition(), {static_cast<float>(pos_x_m),
        static_cast<float>(pos_y_m),static_cast<float>(width_m),
        static_cast<float>(height_m) }
    );
};

void Gui_Namespace::Knopf::update_m(){
    
    if (Knopf::isHovering_m() == true) {
		raylib_namespace::DrawRectangle(pos_x_m, pos_y_m, width_m,
                         height_m, raylib_namespace::RED);
	}
	else {
		raylib_namespace::DrawRectangle(pos_x_m, pos_y_m, width_m, 
                            height_m, raylib_namespace::GRAY);
	}
	raylib_namespace::DrawText(label_m.c_str(), pos_x_m + 10, pos_y_m + 10,
                             20, raylib_namespace::BLACK);

};

bool Gui_Namespace::Knopf::isClicked_m(){
	return raylib_namespace::IsMouseButtonPressed(
        raylib_namespace::MOUSE_LEFT_BUTTON) &&
		raylib_namespace::CheckCollisionPointRec
        (
            raylib_namespace::GetMousePosition(), { static_cast<float>(pos_x_m),
                static_cast<float>(pos_y_m), static_cast<float>(width_m), 
                static_cast<float>(height_m) }
        );
};