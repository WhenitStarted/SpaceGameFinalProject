
#include "Game.h"

Game::Game()
: HEALTH("Health")
{
    gameMusicBuffer.loadFromFile("Music/inGameMusic.ogg");
    maingameMusic.setBuffer(gameMusicBuffer);

    soundBuffer.loadFromFile("Music/EndCreditSong.ogg");
    EndMusic.setBuffer(soundBuffer);

    heartText.loadFromFile("Images/Life.png");
    playerHealth();

    enemyTexture1.loadFromFile("Images/ufo.png");
    enemyTexture2.loadFromFile("Images/Enemy1.png");
    enemyTexture3.loadFromFile("Images/Enemy2.png");
    enemyTexture4.loadFromFile("Images/Enemy_3.png");
    enemyBulletTexture.loadFromFile("Images/EnemyLaser2.png");

    asteroidTexture1.loadFromFile("Images/Asteroid1.png");
    asteroidTexture2.loadFromFile("Images/Asteroid2.png");

    wallTexture.loadFromFile("Images/Barrier.png");
    walls.setTexture(wallTexture);
    walls.setScale(.16,.16);

    HEALTH.setPosition({20, 0});
    HEALTH.setSize({115,50});
    HEALTH.setColor(sf::Color::White);
    HEALTH.setScale(.8,.8);

    pointTexture.loadFromFile("Images/Point.png");
    point.setTexture(pointTexture);
    point.setScale(.4,.4);
    point.setPosition(1000,1000);

    totalPointTexture.loadFromFile("Images/Score.png");
    ScoreImage.setTexture(totalPointTexture);
    ScoreImage.setSize({45,45});
    ScoreImage.setPosition({5,50});

    scoreDisplay.setPosition({50, 43});
}

void Game::enemySpawnCooldown()
{
    for (int i = 0; i < enemyBullets.size(); i++)
    {
        enemyBullets[i].Laser::fireEnemy();
        if (enemyBullets[i].getSprite().getPosition().y < 0)
        {
            enemyBullets.erase(enemyBullets.begin() + i);
            break;
        }
    }

    elapsed_time += r.restart();
    while( elapsed_time >= cooldownEnemy)
    {
        elapsed_time -= cooldownEnemy;
        int textureSelector=rand() % 2 + 1;

        if (textureSelector==1)
            enemies.push_back(Enemy(&enemyTexture3));
        else
        enemies.push_back(Enemy(&enemyTexture4));
    }
    for(int i=0;i<enemies.size();i++)
    {
        enemies[i].Enemy::fire();
        if (enemies[i].sprite.getPosition().y < 3)
            enemyBullets.push_back(Laser(&enemyBulletTexture, enemies[i].sprite.getPosition()));

    }
}



void Game::asteroidsSpawn()
{
    if (timer < 60)
    {
        timer++;
    }
    if (timer >= 60 )
    {
        int textureSelector=rand() % 2 + 1;

        if (textureSelector==1)
            asteroids.push_back(Enemy(&asteroidTexture1));
        else
            asteroids.push_back(Enemy(&asteroidTexture2));
        timer=0;
    }
    for(int i=0;i<asteroids.size();i++)
    {
        asteroids[i].Enemy::altFire();
    }
}


void Game::update()
{
    if(checkState(playerMovement))
    {
        player.Player::update();
        Game::enemySpawnCooldown();
        Game::asteroidsSpawn();
        Game::laserCollisions();
        Game::collisions();
        Game::enemyLaserCollision();
        Game::barrierCollision();
    }

    if(checkState(POINT))
    {
        sf::Color c = this->point.getColor();
            if(c.a==1)
                point.getColor();
            else
            {
                c.a -= 2;
                point.setColor(c);
            }
    }
}
void Game::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    startGame(window, event);
}
bool Game::startGame(sf::RenderWindow &window, sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        enableState(States::playerMovement);
        disableState(NORMAL);
        maingameMusic.play();
        return true;
    }
    if (player.checkState(FADE))
    {
        enableState(States::GAMEOVER);
        maingameMusic.stop();
        return true;
    }
    if (player.checkState(PLAYERTRAVEL))
    {
        enableState(States::PLAYERWIN);
        EndMusic.play();
        maingameMusic.stop();
        return true;
    }

    else
    {
        enableState(NORMAL);
        disableState(HOVERED);
        return false;
    }
}

void Game::playerHealth()
{
    Rectangle s1;
    s1.setTexture(heartText);
    s1.setSize(sf::Vector2f(20,20));
    s1.setPosition({120, 15});
    Rectangle s2;
    s2.setTexture(heartText);
    s2.setSize(sf::Vector2f(20,20));
    s2.setPosition({150, 15});
    Rectangle s3;
    s3.setTexture(heartText);
    s3.setSize(sf::Vector2f(20,20));
    s3.setPosition({180, 15});

    list.push(s1);
    list.push(s2);
    list.push(s3);
}

//polymorphism, you can see this by holding command (control) and clicking on the class name
void Game::draw(sf::RenderTarget &window, sf::RenderStates states)const
{
    if (!checkState(HIDDEN))
    {
        //Asteroid
        for (int i = 0; i < this->asteroids.size(); i++)
            asteroids[i].draw(window);

        //ENEMY SPAWN
        for(int i=0;i<this->enemyBullets.size();i++)
            enemyBullets[i].draw(window);
        for (int i = 0; i < this->enemies.size(); i++)
            enemies[i].draw(window);

        //PLAYER HEALTH
            window.draw(list);
            window.draw(HEALTH);

        //PLAYER AND BULLETS
        for (int i = 0; i < this->player.bullets.size(); i++) //This loops draws the bullets
            player.bullets[i].draw(window);
        window.draw(player.getSprite(), states);

        //Point Image Drawer
        window.draw(point);
        window.draw(ScoreImage);
        window.draw(scoreDisplay);

        //Barrier Draw
        window.draw(wall);
    }
}

void Game::scoreUpdate()
{
    scoreNum=scoreDisplay.getAmount();
    scoreNum+=10;
    scoreDisplay.setAmount(scoreNum);
}

bool Game::collisions()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        sf::FloatRect enemyBounds = enemies[i].getSprite().getGlobalBounds();
        sf::FloatRect playerBound = player.getSprite().getGlobalBounds();
        if (Collision::PixelPerfectTest(enemies[i].getSprite(), player.getSprite()))
        {
            enemies.erase(enemies.begin() + i);
            looseGame();

        }

    }
}

void Game::laserCollisions()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        sf::FloatRect enemyBounds = enemies[i].getSprite().getGlobalBounds();
        for (int j = 0; j < player.getBullets().size(); j++)
        {
            sf::FloatRect playerlaserBound = player.getBullets()[j].getSprite().getGlobalBounds();
            if (Collision::PixelPerfectTest(enemies[i].getSprite(), player.getBullets()[j].getSprite()))
            {
                enemies.erase(enemies.begin() + i);
                player.getBullets().erase(player.getBullets().begin() + j);
                point.setPosition(player.getBullets()[j].getSprite().getPosition());
                point.setColor(sf::Color::White);
                enableState(POINT);
                scoreUpdate();
                addBarrier();
                break;
                }
            }

        }
}

void Game::enemyLaserCollision()
{
    for (int i = 0; i < enemyBullets.size(); i++)
    {
        sf::FloatRect enemyBounds = enemyBullets[i].getSprite().getGlobalBounds();
        sf::FloatRect playerBound = player.getSprite().getGlobalBounds();
        if (Collision::PixelPerfectTest(enemyBullets[i].getSprite(), player.getSprite()))
            {
            enemyBullets.erase(enemyBullets.begin() + i);
                list.pop();
                if(list.empty())
                {
                    player.enableState(FADE);
                    enableState(GAMEOVER);
                }
            break;
        }
    }
}

int Game::barrierCollision()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if(!wall.empty())
        {
            for (wall.start(); !wall.atEnd();wall.forward())
            {
                if (Collision::PixelPerfectTest(enemies[i].getSprite(), wall.getCurrentData()))
                {
                    enemies.erase(enemies.begin() + i);
                    //WALL REARANGE
                    wall.pop_back();
                    pushSpace=walls.getPosition().x;
                    pushSpace-=70;
                    walls.setPosition(pushSpace,550);
                    checkBarriertoWin();
                    return 5;
                }
            }
        }
    }
}

void Game::looseGame()
{
    list.pop();
    if(list.empty())
    {
        player.enableState(FADE);
        enableState(GAMEOVER);
    }
}

bool Game::checkBarriertoWin()
{
        if(wall.size()==7)
        {
        player.enableState(PLAYERTRAVEL);
        enableState(PLAYERWIN);
        }
}

void Game::addBarrier()
{
    if(scoreDisplay.getAmount()==20||scoreDisplay.getAmount()==40||scoreDisplay.getAmount()==60||scoreDisplay.getAmount()==80
       ||scoreDisplay.getAmount()==100||scoreDisplay.getAmount()==120||scoreDisplay.getAmount()==140||scoreDisplay.getAmount()==160
       ||scoreDisplay.getAmount()==180||scoreDisplay.getAmount()==200||scoreDisplay.getAmount()==240||scoreDisplay.getAmount()==260)
    {
        checkBarriertoWin();
        if(wall.size()<7)
        {
            pushSpace=walls.getPosition().x;
            pushSpace+=70;
            walls.setPosition(pushSpace,550);
            wall.push_back(walls);
        }
        if(wall.size()==7)
        {
            player.enableState(PLAYERTRAVEL);
            enableState(PLAYERWIN);
        }
    }
}

Game::~Game()
{

}
