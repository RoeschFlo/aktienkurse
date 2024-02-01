#ifndef AUSGABE_FELD_H
#define AUSGABE_FELD_H

#include "rechteck.h"

namespace Gui_Namespace{
    class Ausgabe_feld: public Rechteck{
        public: Ausgabe_feld(int width, int height, int pos_x, int pos_y, 
                    std::string label);
        

        
            void update_m(const std::string& ref_to_DB);
            void draw();

        private:
            raylib_namespace::Rectangle rect_box_m;

    };
}
#endif //AUSGABE_FELD_H