/* Diese Klasse beinhaltet ALLES, die wichtigsten Funktionen sind
update_all und draw_all*/
#ifndef GUI_H
#define GUI_H

#include "../include/my_includes.h"
#include "../include/button.h"
#include "../include/textbox.h"



namespace Gui_Namespace{
    class Gui{    
        public: 
        Gui();
        void update_all();
        void draw_all();

    button button_obj;
    textbox textbox_obj;
    
    };
}


#endif //GUI