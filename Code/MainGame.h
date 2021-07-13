//
// Created by Nat on 5/27/2021.
//

#ifndef SPACEGAME_MAINGAME_H
#define SPACEGAME_MAINGAME_H

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Rectangle.h"
#include "MainMenu.h"
#include "Game.h"
#include "States.h"

class MainGame:public States
{
private:
    sf::RenderWindow window;
    sf::Texture background;
    sf::Sprite gameCanvas;
    Rectangle pauseButton;
    sf::Texture pauseTexture;
    Game game;
public:
    MainGame();
    void run();
    ~MainGame();


};

#endif //SPACEGAME_MAINGAME_H
