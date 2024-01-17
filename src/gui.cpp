#include "../include/gui.h"
//Beschreibungs siehe gui.h

Gui_Namespace::Gui::Gui():button_obj(200,200,50,50,"save-button"),textbox_obj(600,600,600,50){}



void Gui_Namespace::Gui::update_all(){};


//list your drawing functions here
void Gui_Namespace::Gui::draw_all(){
    button_obj.draw();
    textbox_obj.draw();

};


