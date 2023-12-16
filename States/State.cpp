#include "State.h"

State::State(RenderWindow* window, stack<State*>* state)
{
	this->window = window;
	this->states = state;
	this->end = false;
}

State::~State()
{
}

const bool& State::getEnd() const
{
	return this->end;
}


void State::abortState()
{
	this->end = true;
}




