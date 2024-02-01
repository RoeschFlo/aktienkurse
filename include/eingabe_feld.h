#ifndef EINGABE_FELD_H
#define EINGABE_FELD_H

#include "my_includes.h"
#include "rechteck.h"


namespace Gui_Namespace{
    class Eingabe_feld: public Rechteck {
        public:
            Eingabe_feld(int width, int height, int pos_x, 
                            int pos_y, std::string label);

            void update_m ();
            std::string get_eingabe_m();
        private:
            raylib_namespace::Rectangle rect_box_m;
            std::string eingabe_m;
            char name_m[MAX_INPUT_CHARS + 1];
            bool mouseOnText_m;
            int letterCount_m;
            int framesCounter_m;
    };
}

#endif //EINGABE_FELD_H