#include "../include/button.h"
namespace Gui_Namespace{
button::button(int width, int height, int pos_x, int pos_y, const char *label) :
	width(width),
	height(height),
	pos_x(pos_x),
	pos_y(pos_y),
	label(label)
{}

void button::draw() {
	if (button::isHovering() == true) {
		raylib_namespace::DrawRectangle(pos_x, pos_y, width, height, raylib_namespace::RED);
	}
	else {
		raylib_namespace::DrawRectangle(pos_x, pos_y, width, height, raylib_namespace::GRAY);
	}
	raylib_namespace::DrawText(label, pos_x + 10, pos_y + 10, 20, raylib_namespace::DARKGRAY);

	
}

bool button::isClicked()  {
	return raylib_namespace::IsMouseButtonPressed(raylib_namespace::MOUSE_LEFT_BUTTON) &&
		raylib_namespace::CheckCollisionPointRec(
            raylib_namespace::GetMousePosition(), { static_cast<float>(pos_x), static_cast<float>(pos_y),
												  static_cast<float>(width), static_cast<float>(height) });
}

bool button::isHovering() {
	return raylib_namespace::CheckCollisionPointRec(
        raylib_namespace::GetMousePosition(), { static_cast<float>(pos_x), static_cast<float>(pos_y),
												  static_cast<float>(width), static_cast<float>(height) });
}

void save_button::update() {
	if (button::isClicked()) {
		printf("Update");
	}
}
}