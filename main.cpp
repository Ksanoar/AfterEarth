#include "engine.h"
#include "Scene.h"

sf::RenderWindow* Window = NULL;
sf::Event*        Event  = NULL;

void (*render)(sf::RenderWindow* pWindow) = NULL; 
void (*logic)(void) = NULL;

int main(void) {
	Window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, BPP), TITLE, STYLE);
	Event  = new sf::Event;

	render = IntroRender;
	logic  = IntroLogic;

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
			logic();
			render(Window);

			Window->display();
			Window->clear();
		}
	}

	delete Window;
	return 0;
}