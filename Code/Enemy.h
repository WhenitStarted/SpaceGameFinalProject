
#ifndef SPACEGAME_ENEMY_H
#define SPACEGAME_ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "States.h"

class Enemy:public States
{
private:
    void initialize();
    sf::Texture enemyTexture1;
public:
    Enemy();
    Enemy(sf::Texture *texture);
    void fire() ;
    void altFire();
    const sf::Sprite &getSprite() const;
    sf::Vector2<float> getPos();
    virtual void draw(sf::RenderTarget& target)const;
    void getGlobalBounds();
    void setPos(sf::Vector2<float> newPos);
    sf::Vector2u windowSize;
    sf::Sprite sprite;
    ~Enemy();
};

#endif //SPACEGAME_ENEMY_H
