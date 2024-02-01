#include "../include/speicher_knopf.h"

Gui_Namespace::Speicher_knopf::Speicher_knopf(int width, int height, int pos_x, int pos_y, 
                    std::string label):Knopf(width, height, pos_x, pos_y, label)
                    {};

void Gui_Namespace::Speicher_knopf::in_DB_schreiben_m(std::string text,std::string* ptr_to_db_speicher){
    *ptr_to_db_speicher = text; //Wert wird in noch simulierter Datenbank gespeichert
    printf(text.c_str(), " in simulierter Datenbank gespeichert! YEAH");
};