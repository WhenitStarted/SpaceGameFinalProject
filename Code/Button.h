#ifndef SPACEGAME_BUTTON_H
#define SPACEGAME_BUTTON_H

#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "WindowDialog.h"
#include "States.h"
#include <vector>
#include <iostream>
class Button : public sf::Drawable, public sf::Transformable, public States
{

private:
    sf::RectangleShape background;
    sf::Text text;
    sf::Vector2f size;
    sf::Color color;
    sf::Texture texture;
    void initialize();
    bool hover(sf::RenderWindow& window, sf::Event event);
    void center();
public:
    Button();
    Button(std::string text, sf::Vector2f size, sf::Color color);
    Button(std::string text);
    void setScale (float factorX, float factorY);
    //polymorphismm, pure virtual function defined
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds();
    void setBackground(const sf::RectangleShape &background);
    void setTexture(const sf::Texture &texture);
    void setSize(const sf::Vector2f &size);
    void setColor(const sf::Color &color);
};



#endif //SPACEGAME_BUTTON_H
