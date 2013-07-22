#include "engine.h"
#include "Scene.h"

sf::RenderWindow* Window = NULL;
sf::Event*        Event  = NULL;

void (*render)(float dt) = NULL;

float dt = 0.0f;

sf::Time lastTime, currTime;
sf::Clock Clock;

float fps = 0.0f, fpsTime = 0.0f;
unsigned int frames = 0;

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

			++frames;
			fpsTime += dt;

			if(fpsTime >= 1.0f) {
				fps = frames/fpsTime;
				frames = 0;
				fpsTime = 0.0f;
			}
		}
	}

	delete Window;
	return 0;
}