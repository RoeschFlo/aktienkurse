#ifndef TEST_H
#define TEST_H
#include "global_stuff.h"



class drawing_interface {

public:
	
	drawing_interface() {
		texture_obj = LoadTexture(ASSETS_PATH"test.png"); // Check README.md for how this works
	};
	Texture2D texture_obj;
	
	void draw();
};




#endif //TEST_H