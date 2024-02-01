#ifndef KNOPF_H
#define KNOPF_H

#include "my_includes.h"
#include "rechteck.h"

namespace Gui_Namespace{
    class Knopf: public Rechteck
    {
    protected:
        /* data */
    public:
        Knopf(int width, int height, int pos_x, int pos_y, 
                    std::string label);
        

        void update_m();
        bool isClicked_m();
	    bool isHovering_m();

    };
    
    
}


#endif //KNOPF_H