#include "Health.h"
Health::Health()
{
    initialize();
}

void Health::initialize()
{
    heartTexture.loadFromFile("Images/Life.png");
    this->sprite.setTexture(heartTexture );
    sprite.setScale(sf::Vector2f(.15,.15));
    sprite.setPosition(rand() % (int)(windowSize.x - this->sprite.getLocalBounds().width), 0);
}

void Health::setPos(sf::Vector2<float> newPos)
{
    sprite.setPosition(newPos);
}

sf::Vector2<float> Health::getPos()
{
    return sprite.getPosition();
}

void Health::draw(sf::RenderTarget &window)const
{
        window.draw(sprite);
}

const sf::Sprite &Health::getSprite() const {
    return sprite;
}

Health::~Health()
{
}