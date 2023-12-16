#include "Platforms.h"


void Platforms::initTex()
{
	this->tex1.loadFromFile(PLATFORM);
	this->plat.setTexture(tex1);
	this->plat.scale(1.5,1.5);
}

std::vector<Vector2f> Platforms::getPos()
{
	return position;
}

float Platforms::getTheHighestPlat()
{
	return theHighest;
}

Platforms::Platforms()
{
	float y1 = float(WIN_HEIGHT);
	float x1 = float(WIN_WIDTH / 2.f);
	theHighest =-200;
	this->initTex();

	for (int i = 0; i < NUM_OF_PLATS; i++)
	{
		xy.x = x1;
		xy.y = y1;

		position.push_back(xy);
		y1 -= 200.f;
		x1 = this->plat.getLocalBounds().width/2.f + rand() % WIN_WIDTH - this->plat.getLocalBounds().width/2.f;
		if (x1 + plat.getGlobalBounds().width/2.f > WIN_WIDTH)
		{
			x1 -= plat.getGlobalBounds().width;
		}
	}


}

Platforms::~Platforms()
{
}

bool Platforms::jumpedOn(Jumper* doodle)
{
	for (int i = 0; i < NUM_OF_PLATS; i++)
	{
		if (!doodle->isJumping() && doodle->getPosition().x + doodle->getWidth() > position[i].x && doodle->getPosition().x < position[i].x + doodle->getWidth() &&
			doodle->getPosition().y +doodle->getHeight()< position[i].y +20 && doodle->getHeight() + doodle->getPosition().y>position[i].y)
		{
			doodle->setOnPlat(true);
			doodle->jump();
			this->drop(doodle);

			return true;
		}
	}
	doodle->setOnPlat(false);
	return false;
}



void Platforms::drop(Jumper* doodle)
{
		for (int i = 0; i < NUM_OF_PLATS; i++)
		{
			if (position[i].y>doodle->getPosition().y+300)
			{
				position[i].y =theHighest-200;
				theHighest = position[i].y;

				position[i].x = this->plat.getLocalBounds().width / 2.f + rand() % WIN_WIDTH - this->plat.getLocalBounds().width / 2.f;
				if (position[i].x + plat.getGlobalBounds().width > WIN_WIDTH)
				{
					position[i].x -= plat.getGlobalBounds().width;
				}
			}

		}
		
}

void Platforms::show(RenderTarget* target)
{
	for (int i = 0; i < NUM_OF_PLATS; i++)
	{
		plat.setPosition(position[i]);
		target->draw(this->plat);
	}

}