#include "Button.h"
#include "../Physic.h"

#include <cstdio>

void Button::draw() {
	if(AABB::check(Object2D(_x, _y, _w, _h), Object2D((float)sf::Mouse::getPosition(*Window).x, (float)sf::Mouse::getPosition(*Window).y, 1, 1)))
		mouseon = true;
	else
		mouseon = false;

	if(mouseon == true && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		clicked = true;

	system("cls");
	printf("X: %f\nY: %f\nW: %f\nH: %f\n\n", _x, _y, _w, _h);
	printf("X: %f    Y: %f", (float)sf::Mouse::getPosition(*Window).x, (float)sf::Mouse::getPosition(*Window).y);

	_spr.setPosition(_x, _y);

	if(mouseon == true) _spr.setTexture(_tex_hi);
	else _spr.setTexture(_tex);

	Window->draw(_spr);
}