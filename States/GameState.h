#pragma once
#include "State.h"
#include "../Jumper.h"
#include "../Platforms.h"

class GameState : public State
{
private:
	Font font;
	Text text;

	Texture backgroundTexture;
	Sprite background;

	Jumper* jumper;
	Platforms* platforms;
	View view, defaultView;

	bool jumperDead;

public:
	GameState(RenderWindow*window, stack<State*>* state);
	virtual ~GameState();

	void initVar();
	void initTex();


	void update();
	void updatePlat();
	void updateDoodle();
	void updateView();


	void show(RenderTarget*target=nullptr);
	void abort();
};

