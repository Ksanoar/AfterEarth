#include "engine.h"

sf::RenderWindow* Window = NULL;
sf::Event*        Event  = NULL;

int main(void) {
	Window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, BPP), TITLE, STYLE);
	Event  = new sf::Event;

	while(Window->isOpen()) {
		if(Window->pollEvent(*Event)) {
			switch(Event->type) {
			case sf::Event::Closed:
				Window->close();
				break;
			default:
				break;
			}
		}
		else {


			Window->display();
			Window->clear();
		}
	}

	delete Window;
	return 0;
}