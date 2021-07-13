#ifndef SPACEGAME_HEALTH_H
#define SPACEGAME_HEALTH_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "States.h"

class Health:public States
        {


private:
    void initialize();
    sf::Sprite sprite;
    sf::Texture heartTexture;

public:
    Health();
    const sf::Sprite &getSprite() const;
    sf::Vector2<float> getPos();
    virtual void draw(sf::RenderTarget& target)const;
    void getGlobalBounds();
    void setPos(sf::Vector2<float> newPos);
    sf::Vector2u windowSize;
    ~Health();



};


#endif //SPACEGAME_HEALTH_H
