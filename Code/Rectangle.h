#ifndef SPACEGAME_RECTANGLE_H
#define SPACEGAME_RECTANGLE_H


#include <SFML/Graphics.hpp>
#include "States.h"

class Rectangle : public sf::Drawable, public States
{
private:
    sf::Clock clock;
    sf::RectangleShape rectangle;
    sf::Texture texture;
public:
    void setTexture(const sf::Texture &texture);

public:
    Rectangle();
    void center();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    sf::FloatRect getGlobalBounds();

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
};



#endif //SPACEGAME_RECTANGLE_H
