#ifndef SPEICHER_KNOPF_H
#define SPEICHER_KNOPF_H

#include "knopf.h"

namespace  Gui_Namespace{
    class Speicher_knopf : public Knopf
    {
    private:
        std::string eingabe_text;
    public:
        Speicher_knopf(int width, int height, int pos_x, int pos_y, 
                    std::string label);
        
        void  in_DB_schreiben_m(std::string text, std::string* db_speicher);
        

    };    
}




#endif