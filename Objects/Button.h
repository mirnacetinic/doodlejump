#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Button : RectangleShape
{
public:
    Button(float width, float height, const String string,Font* font)
    {
       setSize(Vector2f(width, height));
       setFillColor(Color::Black);
       this->text.setFont(*font);
       this->text.setString(string);
       this->text.setCharacterSize(50);
       this->text.setPosition(getPosition().x + width / 2 - text.getLocalBounds().width / 2, getPosition().y + height / 2 - text.getLocalBounds().height / 2);
    }

    void setPosition(float x, float y)
    {
        RectangleShape::setPosition(x, y);
        this-> text.setPosition(x + getSize().x / 2 - text.getLocalBounds().width / 2, y+ text.getLocalBounds().height / 2);
    }

    bool pressed(RenderWindow* window)
    {
        if (getGlobalBounds().contains(Mouse::getPosition(*window).x,Mouse::getPosition(*window).y))
        {
           setFillColor(Color::Cyan);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                return true;
            }
            return false;
        }

        else
        {
            setFillColor(Color::Black);
            return false;
        }
    }

    void show(RenderTarget* target)
    {
        target->draw(*this);
        target->draw(this->text);
    }

private:
    Text text;
};