#include "../include/ausgabe_knopf.h"

Gui_Namespace::Ausgabe_knopf::Ausgabe_knopf(int width, int height, 
    int pos_x, int pos_y, std::string label):Knopf(width, height,
    pos_x,pos_y,label)
    {};


std::string Gui_Namespace::Ausgabe_knopf::aus_DB_lesen_m(std::string* text){
    ausgabe_text_m=*text;
    printf("Ich habe folgendes aus DB gelesen: ");
    printf( ausgabe_text_m.c_str()); printf("\n");
    return *text;
}