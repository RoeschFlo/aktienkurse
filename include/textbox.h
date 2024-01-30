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
            int width_m = 0, height_m = 0, pos_x_m = 0, pos_y_m = 0;
	        const char *label_m= "Place your mouse over input box";
            bool mouseOnText_m = false;
            raylib_namespace::Rectangle textbox_m;
    };
}


#endif // TEXTBOX_HEADER