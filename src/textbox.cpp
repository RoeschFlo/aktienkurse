#include "../include/textbox.h"


Gui_Namespace::textbox::textbox(int width, int height, int pos_x, int pos_y):
    width(width),
	height(height),
	pos_x(pos_x),
	pos_y(pos_y){};


void Gui_Namespace::textbox::update(){};

void Gui_Namespace::textbox::draw(){
    raylib_namespace::DrawRectangle(width,height,pos_x,pos_y, raylib_namespace::GREEN);
}

