#ifndef AUSGABE_FELD_H
#define AUSGABE_FELD_H

#include "rechteck.h"

namespace Gui_Namespace{
    class Ausgabe_feld: public Rechteck{
        public: Ausgabe_feld(int width, int height, int pos_x, int pos_y, 
                    std::string label);
        ~Ausgabe_feld();

        public: //Todo: Zufgriff anpassen
            void draw(int width, int height, int pos_x, int pos_y, 
                    std::string label);
    };
}
#endif //AUSGABE_FELD_H