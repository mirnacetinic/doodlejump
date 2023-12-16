#include "GameObject.h"


GameObject::GameObject()
{

}

GameObject::~GameObject()
{
}

void GameObject::setSprite()
{
	this->sprite.setTexture(this->texure);
}


void GameObject::setPosition()
{
	this->sprite.setPosition(this->position);
}

Vector2f GameObject::getPosition()
{
	return this->position;
}

const float GameObject::getWidth()
{
	return (this->sprite.getTextureRect().width);
}

const float GameObject::getHeight()
{
	return (this->sprite.getTextureRect().height);
}

void GameObject::show(RenderTarget* target)
{
	target->draw(this->sprite);
}
