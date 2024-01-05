#include "button.h"

button::button(int width, int height, int pos_x, int pos_y, const char *label) :
	width(width),
	height(height),
	pos_x(pos_x),
	pos_y(pos_y),
	label(label)
{}

void button::draw() {
	if (button::isHovering() == true) {
		DrawRectangle(pos_x, pos_y, width, height, RED);
	}
	else {
		DrawRectangle(pos_x, pos_y, width, height, GRAY);
	}
	DrawText(label, pos_x + 10, pos_y + 10, 20, DARKGRAY);
	
}

bool button::isClicked()  {
	return IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), { static_cast<float>(pos_x), static_cast<float>(pos_y),
												  static_cast<float>(width), static_cast<float>(height) });
}

bool button::isHovering() {
	return CheckCollisionPointRec(GetMousePosition(), { static_cast<float>(pos_x), static_cast<float>(pos_y),
												  static_cast<float>(width), static_cast<float>(height) });
}