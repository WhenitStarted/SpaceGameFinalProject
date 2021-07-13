#include "Rectangle.h"


Rectangle::Rectangle()
{

}

void Rectangle::update()
{
    if(checkState(FADE))
    {
        sf::Color c = rectangle.getFillColor();
        if(clock.getElapsedTime().asMilliseconds() > 1)
        {
            c.a -= 1;
            rectangle.setFillColor(c);
            clock.restart();
        }
    }
}

void Rectangle::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
        window.draw(rectangle);

}

void Rectangle::center()
{

}

void Rectangle::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Rectangle::setSize(sf::Vector2f size)
{
    rectangle.setSize(size);
}

void Rectangle::setPosition(sf::Vector2f position)
{
    rectangle.setPosition(position);
}

void Rectangle::setTexture(const sf::Texture &texture)
{
    rectangle.setTexture(&texture);
}
sf::FloatRect Rectangle::getGlobalBounds()
{
    return rectangle.getGlobalBounds();
}