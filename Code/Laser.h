//
// Created by Nat on 5/12/2021.
//

#ifndef SPACEGAME_LASER_H
#define SPACEGAME_LASER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "States.h"
#include "Entity.h"


class Laser:public States
{
private:
    void initialize();
    void setColor(const sf::Color &color);
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Color color;

public:
    Laser();
    Laser(sf::Texture *texture, sf::Vector2f pos);
    void setSprite();
    const sf::Color &getColor() const;
    void fire() ;
    void fireEnemy();
    void setPos(sf::Vector2<float> newPos);
    void setPosi(float x,float y);
    sf::Vector2<float> getPos();
    virtual void draw(sf::RenderTarget& target)const ;
    const sf::Sprite &getSprite() const;
   ~Laser();
};


#endif //SPACEGAME_LASER_H
