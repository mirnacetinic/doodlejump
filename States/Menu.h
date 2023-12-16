#pragma once
#include "GameState.h"
#include "../Objects/Button.h"


class Menu : public State
{ 
private:
	Font font;
	Text text;
	Texture backgroudTex;
	Sprite background;

	Button* playButton;
	Button* exitButton;

public:
	Menu(RenderWindow* window, stack<State*>* state);
	virtual ~Menu();

	void initTex();
	void initButtons();

	void update();
	void show(RenderTarget* target = nullptr);
};
