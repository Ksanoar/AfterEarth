#include "Button.h"
#include "../Physic.h"

void Button::draw() {
	if(AABB::check(Object2D(_x, _y, _w, _h), Object2D((float)sf::Mouse::getPosition(*Window).x, (float)sf::Mouse::getPosition(*Window).y, 1, 1)))
		mouseon = true;
	else
		mouseon = false;

	if(mouseon == true && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		clicked = true;

	_spr.setPosition(_x, _y);

	if(mouseon == true) _spr.setTexture(_tex_hi);
	else _spr.setTexture(_tex);

	Window->draw(_spr);
}

