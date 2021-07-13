#include "player.h"


Player::Player() : Player("Text")
{
}

Player::Player(std::string text, sf::Vector2f size, sf::Color color) : color(color)
{
    sprite.setPosition(240,440);
    sprite.scale(.17,.17);
    initialize();
}

Player::Player(std::string text) : Player(text, {100, 50}, sf::Color::Magenta)
{
}

void Player::center()
{
    sf::FloatRect pBounds = sprite.getGlobalBounds();
    sf::FloatRect lBounds = laser.getSprite().getGlobalBounds();

    laser.setPosi(pBounds.width / 2 - lBounds.width / 2,
                  pBounds.top + pBounds.height / 2 - lBounds.height);
}

void Player::initialize()
{
    texture.loadFromFile("Images/ship1.png");
    death.loadFromFile("Images/Death.png");
    winTexture.loadFromFile("Images/SpiralGalaxy.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    center();
}

//polymorphism, you can see this by holding command (control) and clicking on the class name
void Player::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    // states.transform = getTransform();
    if (!checkState(HIDDEN))
    {

        for(int i=0;i<this->bullets.size();i++) //This loops draws the bullets
        {
            bullets[i].draw(window);
        }
        window.draw(sprite, states);
//        window.draw(heart);
    }

}

//event handler
void Player::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    startGame(window, event);
}


//make any necessary updates
void Player::update()
{
    if(checkState(States::PLAYERTRAVEL))
    {
        setWonTexture();
        sf::Color c = this->sprite.getColor();
        if(c.a==1)
        {
            this->sprite.setColor(sf::Color::Transparent);
            sprite.setPosition(1000,1000);
        }
        else
        {
            c.a -= 2;
            sprite.setColor(c);
        }
    }

    if(checkState(FADE))
    {
        setDamagedTexture();

        sf::Color c = this->sprite.getColor();
        if(c.a==1)
        {
            this->sprite.setColor(sf::Color::Transparent);
            sprite.setPosition(1000,1000);
        }
        else
        {
            c.a -= 2;
            sprite.setColor(c);
        }
    }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            moveY=-velocity;
            sprite.move(0,-1.5f);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveY=velocity;
            sprite.move(0,1.5f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            moveX=-velocity;
            sprite.move(-1.5f,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            moveX=velocity;
            sprite.move(1.5f,0);
        }
        push(moveX, moveY);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            shoot(bullets);
        }
    for(int i=0;i<this->bullets.size();i++) //This loops draws the bullets
    {
        bullets[i].fire();
    }

}

void Player::push(float moveXx,float moveYy)
{
    sprite.move(moveXx,moveYy);
}


bool Player::startGame(sf::RenderWindow &window, sf::Event event)
{
    sf::FloatRect bBounds = sprite.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        enableState(States::playerMovement);
        disableState(NORMAL);
        return true;
    }
    else
    {
        enableState(NORMAL);
        disableState(HOVERED);
        return false;
    }
}

sf::FloatRect Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

void Player::setPosition(sf::Vector2f position)
{
    sf::Transformable::setPosition(position);
    sf::Vector2f bBounds = sprite.getPosition();
//    sf::Vector2f tBounds = text.getPosition();
    sprite.setPosition(sf::Transformable::getTransform().transformPoint(bBounds));
//    text.setPosition(sf::Transformable::getTransform().transformPoint(tBounds));
}

void Player::shoot( std::vector<Laser>& bullets)
{
    sf::FloatRect pBounds = this->sprite.getGlobalBounds();
    sf::FloatRect lBounds = laser.getSprite().getGlobalBounds();

    elapsed_time += r.restart();
    while( elapsed_time >= cooldown )
    {
        elapsed_time -= cooldown;
        laser.setPos(getCenter());
        this->bullets.push_back(laser);
//        std::cout<<"SHOOTING"<<elapsed_time.asSeconds()<<std::endl;
    }
}

const sf::Sprite &Player::getSprite() const {
    return sprite;
}

void Player::setSprite(const sf::Sprite &sprite)
{
    Player::sprite = sprite;
}

sf::Vector2<float> Player::getCenter()
{
    return sprite.getPosition() + sf::Vector2f(-23, -20);
//    getPosition();
}
std::vector<Laser> &Player::getBullets()  {
    return bullets;
}

const sf::Texture &Player::getTexture() const {
    return texture;
}

void Player::setDamagedTexture()
{
    sprite.setTexture(death);
}

void Player::setWonTexture()
{
    sprite.setTexture(winTexture);
}

Player::~Player()
{

}