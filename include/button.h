#ifndef BUTTON_H
#define BUTTON_H

#include "global_defines.h"
#include "../include/my_includes.h"


namespace Gui_Namespace{
class button {
public:

	button(int width, int height, int pos_x, int pos_y, const char *label,
			 void(*ptr)(const std::string));

	void draw();
	void polling();
	bool isClicked();
	bool isHovering();

	std::string whriting_string_m();

private:
	int width = 0, height = 0, pos_x = 0, pos_y = 0;
	const char *label= ""; 

	void (*action_ptr_m)(std::string);

};


}
#endif