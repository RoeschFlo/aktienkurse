#include "../include/textbox.h"


Gui_Namespace::textbox::textbox(int width, int height, int pos_x, int pos_y):
    width_m(width),
	height_m(height),
	pos_x_m(pos_x),
	pos_y_m(pos_y){textbox_m ={(float)pos_x, (float)pos_y,(float)width, (float)height};
	};


void Gui_Namespace::textbox::update(){
	
	 if (raylib_namespace::CheckCollisionPointRec(
			raylib_namespace::GetMousePosition(), textbox_m)) mouseOnText_m = true;
        else mouseOnText_m = false;
		
	if (mouseOnText_m == true) {
		raylib_namespace::SetMouseCursor(raylib_namespace::MOUSE_CURSOR_IBEAM);
	}
	else {
		raylib_namespace::SetMouseCursor(raylib_namespace::MOUSE_CURSOR_DEFAULT);
	}

	
};

void Gui_Namespace::textbox::draw(){
    
	raylib_namespace::DrawRectangle(textbox_m.x,textbox_m.y,textbox_m.width,
									textbox_m.height, raylib_namespace::GREEN);
}

