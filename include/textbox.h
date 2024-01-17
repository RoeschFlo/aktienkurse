#ifndef TEXTBOX_HEADER
#define TEXTBOX_HEADER

#include "../include/my_includes.h"


namespace Gui_Namespace{
    class textbox{
        public:
           textbox(int width, int height, int pos_x, int pos_y);

            void draw();
            void update();

        private:
            int width = 0, height = 0, pos_x = 0, pos_y = 0;
	        const char *label= "Place your mouse over input box";
    };
}


#endif // TEXTBOX_HEADER