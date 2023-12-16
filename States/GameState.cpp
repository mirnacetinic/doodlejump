#include "GameState.h"

void GameState::initVar()
{
	this->jumper = new Jumper();
	this->platforms = new Platforms();

	this->view.setSize(WIN_WIDTH, WIN_HEIGHT);
	this->defaultView = window->getDefaultView();
	this->view.setCenter(WIN_WIDTH / 2.f, jumper->getPosition().y - this->jumper->getHeight());

	this->background.scale(2, 2);
	this->background.setTexture(this->backgroundTexture);
}

void GameState::initTex()
{
	this->backgroundTexture.loadFromFile(BACKGROUND);
	this->font.loadFromFile(FONT);

	this->text.setFont(font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(Color::Black);
}

GameState::GameState(RenderWindow* window, stack<State*>* state) :State(window, state)
{
	this->jumperDead = 0;
	this->initTex();
	this->initVar();

}


GameState::~GameState()
{
	delete this->jumper;
}


void GameState::update()
{
	this->updatePlat();
	this->updateDoodle();
	this->updateView();
	this->text.setString("Score: " + to_string(this->jumper->getScore()));
	this->text.setPosition(WIN_WIDTH / 2.f - this->text.getGlobalBounds().width/2.f, 0.f);

	if (this->jumperDead)
	{
		this->abortState();
	}

}

void GameState::updatePlat()
{
	if (!jumperDead){
		this->platforms->jumpedOn(this->jumper);
	}

}

void GameState::updateDoodle()
{
	this->jumper->update();

	if (this->jumper->getPosition().y -this->jumper->getHeight() > this->platforms->getTheHighestPlat() +1500)
	{
		this->jumperDead=1;
	}

}

void GameState::updateView()
{
	this->view.setCenter(WIN_WIDTH / 2.f, jumper->getPosition().y - this->jumper->getHeight());
}



void GameState::show(RenderTarget* target)
{
	this->window->setView(defaultView);
	target->draw(this->background);
	target->draw(this->text);


	this->window->setView(view);
	this->platforms->show(target);
	this->jumper->show(target);
}
