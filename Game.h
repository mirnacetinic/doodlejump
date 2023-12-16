#pragma once
#include "States/GameState.h"
#include "States/Menu.h"

class Game
{
private:
	RenderWindow* window;
	stack<State*> state;

	//inicijalizacija
	void initWin();
	void initState();
	

public:
	//Konstruktor i destruktor
	Game();
	virtual ~Game();

	void play();

	//update vrijednosti
	void update();
	void closeWin();

	//crtanje
	void show();

};

