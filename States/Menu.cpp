#include "Menu.h"

Menu::Menu(RenderWindow* window, stack<State*>*state):State(window,state)
{
	this->initTex();
	this->background.scale(2, 2);
	this->background.setTexture(backgroudTex);
	this->text.setPosition(WIN_WIDTH / 2.f, WIN_HEIGHT /2.f -200.f);
	this->initButtons();

}

void Menu::initTex()
{
	this->backgroudTex.loadFromFile(BACKGROUND);
	this->font.loadFromFile(FONT);

	this->text.setFont(font);
	this->text.setString("DOODLE JUMP");
	this->text.setCharacterSize(100);
	this->text.setFillColor(Color::Black);

}

void Menu::initButtons()
{
	this->playButton = new Button(150.f,100.f, "Play!",&font);
	this->exitButton = new Button(150.f, 100.f, "Exit!",&font);

	playButton->setPosition(WIN_WIDTH / 2.f - 150, WIN_HEIGHT / 2.f);
	exitButton->setPosition(WIN_WIDTH / 2.f+50, WIN_HEIGHT / 2.f);
}

Menu::~Menu()
{
	delete this->playButton;
	delete this->exitButton;
}


void Menu::update()
{
	if (this->playButton->pressed(this->window))
	{
		this->states->push(new GameState(this->window,this->states));
	}

	if (this->exitButton->pressed(this->window))
	{
		this->abortState();
	}


}


void Menu::show(RenderTarget* target)
{
	this->window->setView(this->window->getDefaultView());
	target->draw(this->background);

	this->playButton->show(target);
	this->exitButton->show(target);
	target->draw(this->text);
}
