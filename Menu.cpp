#include "Scene.h"
#include "Utils.h"

Button* NewGame  = NULL;
Button* LoadGame = NULL;
//Button* Settings = NULL;
Button* Exit     = NULL;

bool loaded = false;

void MenuRender(float dt) {
	if(!loaded) {
		NewGame = new Button(100, 100, 248, 36, "./data/gui/new.png", "./data/gui/new_hi.png");
		LoadGame = new Button(200, 200, 248, 36, "./data/gui/load.png", "./data/gui/load_hi.png");
		//Settings = new Button(300, 300, 248, 36, "./data/gui/set.png", "./data/gui/set_hi.png");
		Exit = new Button(400, 400, 248, 36, "./data/gui/exit.png", "./data/gui/exit_hi.png");

		loaded = true;
	}

	NewGame->draw();
	LoadGame->draw();
	//Settings->draw();
	Exit->draw();

	Window->display();
	Window->clear();

	if(NewGame->mouseon && NewGame->clicked) {
		render = IntroRender;

		Utils::unloadAsset(NewGame);
		Utils::unloadAsset(LoadGame);
	//	Utils::unloadAsset(Settings);
		Utils::unloadAsset(Exit);
	}
}