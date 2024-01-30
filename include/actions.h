#ifndef ACTIONS_H
#define ACTIONS_H

#include "my_includes.h"


namespace Gui_Namespace{
    class prt_table{
        public:
            prt_table();

        std::string empty_string;
    
        void action_1( std::string string);
        void (Gui_Namespace::prt_table::*action_1_ptr)(std::string);
    
    };
}


#endif //ACTIONS_H