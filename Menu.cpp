#include "Scene.h"

Button* NewGame = NULL;

bool loaded = false;
bool finished = false;

void MenuRender(float dt) {
	if(!loaded) {
		NewGame = new Button(100, 100, 300, 100, "./first.png", "./second.png");
		loaded = true;
	}
	if(loaded && finished) {
		delete NewGame;
	}

	NewGame->draw();

	Window->display();
	Window->clear();
}