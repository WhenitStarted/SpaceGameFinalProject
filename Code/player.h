
#ifndef SPACEGAME_PLAYER_H
#define SPACEGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "States.h"
#include <vector>
#include "Laser.h"
#include "Button.h"
#include "Rectangle.h"

class Player: public sf::Drawable, public sf::Transformable, public States
{
private:
    sf::Sprite sprite;
    void center();
    void initialize();
    void push(float moveX, float moveY); //pushing player or gives effect of zero gravity "floating"
    float velocity = 1.3;
    float moveX = 0; //move value for X direction
    float moveY = 0; //move value for y direction
    sf::Time elapsed_time;
    sf::Clock r;
    sf::Clock clock;
    sf::Vector2<float> getCenter();
public:
    sf::Texture texture,death,winTexture;
    void setDamagedTexture();
    void setWonTexture();
    const sf::Texture &getTexture() const;
    sf::Color color;
    sf::Time cooldown = sf::seconds(.5);
    Laser laser;
    std::vector<Laser> bullets;
    void shoot(std::vector<Laser>& bullets);

public:
    Player();
    Player(std::string text, sf::Vector2f size, sf::Color color);
    Player(std::string text);
    const sf::Sprite &getSprite() const;
    void setSprite(const sf::Sprite &sprite);
    void setPosition(sf::Vector2f position);
    std::vector<Laser> &getBullets();
    void update();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    bool startGame(sf::RenderWindow &window, sf::Event event);
    ~Player();
    sf::FloatRect getGlobalBounds();
};
#endif //SPACEGAME_PLAYER_H
