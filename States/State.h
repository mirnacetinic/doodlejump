#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <map>
#include "../Jumper.h"

using namespace sf;
using namespace std;


class State
{
protected:
	RenderWindow* window;
	stack<State*>* states;
	bool end;

public:
	State(RenderWindow*window, stack<State*>* state);
	virtual ~State();

	const bool& getEnd() const;
	void abortState();

	virtual void update() = 0;
	virtual void show(RenderTarget*target=nullptr) = 0;

};

