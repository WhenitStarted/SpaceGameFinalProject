#ifndef SPACEGAME_GAME_H
#define SPACEGAME_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include <vector>
#include "Laser.h"
#include "Enemy.h"
#include "player.h"
#include "Collision.h"
#include "Stack.h"
#include"Score.h"
class Game:public sf::Drawable, public sf::Transformable, public States
{
private:
    //OBJECTS
    sf::RenderWindow window;
    Player player;
    Rectangle ScoreImage;
    Score scoreDisplay;
    Button HEALTH;
    //PRIVATE VECTORS AND STACKS
//    Stack<sf::Sprite> wall;
    LinkedList<sf::Sprite>wall;
    Stack<Rectangle> list;
    std::vector<Laser> enemyBullets;
    std::vector<Enemy> enemies;
    std::vector<Enemy> asteroids;
    //TEXTURES AND SPRITES
    sf::Texture enemyTexture1,enemyTexture2,enemyTexture3,enemyTexture4,
            totalPointTexture,asteroidTexture1,asteroidTexture2,wallTexture,
            heartText,pointTexture,enemyBulletTexture;
    sf::Sprite point,walls;
    int scoreNum,pushSpace;
    //SOUND VARIABLES
    sf::Sound maingameMusic;
    sf::SoundBuffer gameMusicBuffer;
    sf::Sound EndMusic;
    sf::SoundBuffer soundBuffer;
private:
    //Collisions
    bool collisions();
    void laserCollisions();
    void enemyLaserCollision();
    int barrierCollision();
    bool checkBarriertoWin();
    void addBarrier();
    //ENEMIES SPAWN
    void enemySpawnCooldown();
    void asteroidsSpawn();
    //MISC
    void playerHealth();
    void scoreUpdate();
    void looseGame();
private:
    //TIME OBJECTS AND VARIABLES FOR SPAWN
    sf::Time elapsed_time;
    sf::Clock r;
    sf::Time cooldownEnemy = sf::seconds(1);
    int	timer = 0;

public:
    Game();
    void update();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const ;
    bool startGame(sf::RenderWindow &window, sf::Event event);
    ~Game();
};


#endif //SPACEGAME_GAME_H
