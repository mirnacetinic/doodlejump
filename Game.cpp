#include "Game.h"

void Game::initWin()
{
	this->window = new RenderWindow(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Doodle Jump", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(90);
}

void Game::initState()
{
	this->state.push(new Menu(this->window,&this->state));
}

Game::Game()
{
	this->initWin();
	this->initState();

}


Game::~Game()
{
	delete this->window;
	while (!this->state.empty())
	{
		//uklanja podatke 
		delete this->state.top();

		//uklanja pointer
		this->state.pop();
	}
	
}

void Game::play()
{
	while (this->window->isOpen())
	{
		this->update();
		this->show();
	}

}


void Game::update()
{
	this->closeWin();

	if (!this->state.empty())
	{
		this->state.top()->update();

		if (this->state.top()->getEnd())
		{
			delete this->state.top();
			this->state.pop();
		}
	}

	else
	{
		this->window->close();
	}

}

void Game::closeWin()
{
	Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == Event::Closed || ev.Event::KeyPressed && ev.Event::key.code == Keyboard::Escape)
		{
			this->window->close();
		}

	}
}

void Game::show()
{
	//brisanje starog
	this->window->clear();

	if (!this->state.empty())
	{
		this->state.top()->show(this->window);
	}
	
	//prikaz novog
	this->window->display();

}


