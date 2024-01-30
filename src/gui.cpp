#include "../include/gui.h"
//Beschreibungs siehe gui.h

Gui_Namespace::Gui::Gui():button_obj(200,200,50,50,"save-button",
                        prt_table_obj.action_1_ptr),
                        textbox_obj(600,50,600,50){}



void Gui_Namespace::Gui::update_all(){
    button_obj.polling();
    textbox_obj.update();
};


//list your drawing functions here
void Gui_Namespace::Gui::draw_all(){
    button_obj.draw();
    textbox_obj.draw();

};


