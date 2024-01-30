#ifndef RECHTECK_H
#define RECHTECK_H

#include "my_includes.h"

namespace Gui_Namespace{
    class Rechteck {
        public: 
            Rechteck(int width, int height, int pos_x, int pos_y, 
                    std::string label);

            
            
        public:
            std::string label_m;
            int width_m;
            int height_m;
            int pos_x_m;
            int pos_y_m;
    };
}




#endif //RECHTECK_H