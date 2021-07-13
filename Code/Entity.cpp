//
// Created by Nat on 5/25/2021.
//

#include "Entity.h"

Entity::Entity()
{

}
Entity::Entity(sf::Texture texture)
:texture(texture)
{
    initialize();
}

Entity::Entity(const Entity &entity)
{
    *this = entity;
}


void Entity::initialize()
{
    texture.loadFromFile("");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(.15,.15));
}

const sf::Texture &Entity::getTexture() const {
    return texture;
}

const sf::Sprite &Entity::getSprite() const {
    return sprite;
}
void Entity::setPos(sf::Vector2<float> newPos)
{
    sprite.setPosition(newPos);
}
sf::Vector2<float> Entity::getPos()
{
    return sprite.getPosition();
}


void Entity::draw(sf::RenderTarget &window)const
{
    if(!checkState(HIDDEN))
        window.draw(sprite);
}


Entity::~Entity() {

}
