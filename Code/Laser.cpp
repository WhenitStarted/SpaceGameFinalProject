#include "Laser.h"

Laser::Laser()
{
    initialize();
}
Laser::Laser(sf::Texture *texture, sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
    this->sprite.setTexture(*texture);
    this->sprite.setScale(sf::Vector2f(.5,.5));

}

void Laser::initialize()
{
    texture.loadFromFile("Images/laser.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(.1,.1));
}

void Laser::fire()
{
    sprite.move(0.f, -3.5f);
}
void Laser::fireEnemy()
{
    sprite.move(0.f, 3.f);
}

void Laser::setPos(sf::Vector2<float> newPos)
{
    sprite.setPosition(newPos);
}

void Laser::setPosi(float x,float y)
{
    sprite.setPosition( x,  y);
}

sf::Vector2<float> Laser::getPos()
{
    return sprite.getPosition();
}

void Laser::draw(sf::RenderTarget &window)const
{
    if(!checkState(HIDDEN))
        window.draw(sprite);
}

const sf::Sprite &Laser::getSprite() const {
    return sprite;
}

Laser::~Laser()
{

}

const sf::Color &Laser::getColor() const {
    return color;
}

void Laser::setColor(const sf::Color &color) {
    Laser::setColor(color);
}

