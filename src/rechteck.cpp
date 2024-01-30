#include "../include/rechteck.h"

Gui_Namespace::Rechteck::Rechteck(int width, int height,
    int pos_x, int pos_y, std::string label):
        width_m(width),
        height_m(height),
        pos_x_m(pos_x),
        pos_y_m(pos_y),
        label_m(label) {}

Gui_Namespace::Rechteck::~Rechteck(){}