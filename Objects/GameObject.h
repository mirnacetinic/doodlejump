#pragma once
#include "SFML/Graphics.hpp"
#include "../definition.h"

using namespace sf;

class GameObject
{

protected:
	Texture texure;
	Sprite sprite;
	Vector2f position;

public:
	GameObject();
	virtual ~GameObject();

	virtual void update() = 0;
	virtual void show(RenderTarget* target);

	void setSprite();
	virtual void setPosition();

	virtual Vector2f getPosition();
	virtual const float getWidth();
	virtual const float getHeight();

};

