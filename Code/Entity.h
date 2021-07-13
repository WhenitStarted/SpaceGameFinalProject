#ifndef SPACEGAME_ENTITY_H
#define SPACEGAME_ENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "States.h"

class Entity:public States
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    void initialize();
public:
    Entity();
    Entity(sf::Texture texture);
    Entity(const Entity& entity);
    void setPos(sf::Vector2<float> newPos);
    sf::Vector2<float> getPos();
    virtual void draw(sf::RenderTarget& target)const ;
    const sf::Texture &getTexture() const;
    const sf::Sprite &getSprite() const;
    ~Entity();


};

#endif //SPACEGAME_ENTITY_H
