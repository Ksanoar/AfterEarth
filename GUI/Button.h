#pragma once

#include "../engine.h"

class Button {
private:
	float _x, _y;
	float _w, _h;

	sf::Texture _tex;
	sf::Texture _tex_hi;
	sf::Sprite  _spr;
public:
	bool mouseon;
	bool clicked;
public:
	Button(float x, float y, float w, float h, std::string fname, std::string fname_hi) : _x(x), _y(y), _w(w), _h(h) { 
		_tex.loadFromFile(fname);
		_tex_hi.loadFromFile(fname_hi);

		mouseon = false;
		clicked = false;
	}
	~Button() { }

	void draw();
};