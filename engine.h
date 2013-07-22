#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

#define WIDTH  800
#define HEIGHT 600
#define BPP    32
#define TITLE  "After Earth"
#define STYLE  sf::Style::Default

extern sf::RenderWindow* Window;
extern sf::Event*        Event;

extern void (*render)(float dt);
