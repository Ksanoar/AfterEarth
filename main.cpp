#include "engine.h"
#include "Scene.h"

sf::RenderWindow* Window = NULL;
sf::Event*        Event  = NULL;

void (*render)(float dt) = NULL; 

float dt = 0.0f;

sf::Time lastTime, currTime;
sf::Clock Clock;

int main(void) {
	Window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, BPP), TITLE, STYLE);
	Event  = new sf::Event;

	render = IntroRender;

	lastTime = Clock.getElapsedTime();

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
			currTime = Clock.getElapsedTime();
			dt = currTime.asSeconds() > lastTime.asSeconds() ? (currTime.asSeconds() - lastTime.asSeconds()) : 0.0f;
			lastTime = currTime;

			render(dt);


		}
	}

	delete Window;
	return 0;
}