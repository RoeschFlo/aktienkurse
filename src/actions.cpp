#include "../include/actions.h"

namespace Gui_Namespace{

prt_table::prt_table(){
    empty_string="";
    action_1_ptr= &action_1;

}


//void (*action_1_ptr)(std::string) = &action_1;



void prt_table::action_1( std::string string){
    std::printf("Update");
}

}