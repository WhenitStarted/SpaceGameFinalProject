
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(sf::Texture *texture)
{
    this->sprite.setTexture(*texture);
    initialize();
}

void Enemy::initialize()
{
    int posX=rand() % 550 + 0;
    int posY=1;
    sprite.setPosition(sf::Vector2f(posX,posY));
    sprite.setScale(.17,.17);
}


void Enemy::fire()
{
    this->sprite.move(0.f, 1.2f);
}

void Enemy::altFire()
{
    sprite.setScale(.4,.4);
    sprite.rotate(3);
    this->sprite.move(0.f, 5.f);
}

void Enemy::setPos(sf::Vector2<float> newPos)
{
    sprite.setPosition(newPos);
}

sf::Vector2<float> Enemy::getPos()
{
    return sprite.getPosition();
}

void Enemy::draw(sf::RenderTarget &window)const
{
    if(!checkState(HIDDEN))
        window.draw(sprite);
}

const sf::Sprite &Enemy::getSprite() const {
    return sprite;
}


Enemy::~Enemy()
{
}