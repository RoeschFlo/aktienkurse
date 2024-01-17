#ifndef BUTTON_H
#define BUTTON_H

#include "global_defines.h"
#include "../include/my_includes.h"


namespace Gui_Namespace{
class button {
public:

	button(int width, int height, int pos_x, int pos_y, const char *label);

	void draw();
	bool isClicked();
	bool isHovering();

private:
	int width = 0, height = 0, pos_x = 0, pos_y = 0;
	const char *label= ""; 

};

class save_button : public button {
public:
	save_button(int width, int height, int pos_x, int pos_y, const char *label) :
		button(width, height, pos_x, pos_y, label) {

	}
	void update();
};

}
#endif