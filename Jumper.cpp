#include "Jumper.h"

void Jumper::initTex()
{
	this->texure.loadFromFile(DOODLER);
	this->setSprite();
}


int Jumper::getScore()
{
	return this->score;
}

bool Jumper::getonPlat()
{
	return this->onPlat;
}

bool Jumper::isJumping()
{
	return this->jumping;
}

Jumper::Jumper() :jumpLen(0), onPlat(1),jumping(0)
{
	this->initTex();

	this->position.x = 300.f;
	this->position.y= 700.f;
	this->lastY = 700.f;
	this->score = 0;
	this->setPosition();
}

Jumper::~Jumper()
{
}

void Jumper::move(const float x1, const float y1)
{
	this->sprite.move(SPEED * x1,SPEED * y1);
}

void Jumper::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (this->position.x <= 0- this->getWidth())
		{
			position.x = 600;
		}

		else {
			this->sprite.move(-2.f * SPEED, 0.f);
			position.x -= 2 * SPEED;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (this->position.x >= 600+this->getWidth())
		{
			position.x =-this->getWidth();
		}

		else {
			this->sprite.move(+2.f * SPEED, 0.f);
			position.x += 2 * SPEED;
		}
	}

	jumping = 0;
	jumpLen += GRAVITY;
	position.y+= jumpLen;

	if (jumpLen < 0)
	{
		jumping = 1;
	}

	this->setPosition();
}


void Jumper::setOnPlat(bool i)
{
	onPlat = i;
}


void Jumper::jump()
{

	jumpLen = -10;
	if (position.y + this->getHeight() < lastY)
	{
		lastY = position.y;
		score++;
	}
}


