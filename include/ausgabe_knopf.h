#ifndef AUSGABE_KNOPF_H
#define AUSGABE_KNOPF_H

#include "my_includes.h"
#include "knopf.h"

namespace  Gui_Namespace{
    class Ausgabe_knopf : public Knopf
    {
    private:
        std::string ausgabe_text_m;
    public:
        Ausgabe_knopf(int width, int height, int pos_x, int pos_y, 
                    std::string label);
        
        
        std::string aus_DB_lesen_m(std::string* text);
        

    };    
}

#endif