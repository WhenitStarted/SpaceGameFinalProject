
#include "MainGame.h"

MainGame::MainGame() : window({600, 600, 32}, "THE VOID")
{
window.setFramerateLimit(60);
}

void MainGame::run()
{
    MainMenu mainMenu;
    background.loadFromFile("Images/SpaceBackground.png");
    gameCanvas.setTexture(background);
    gameCanvas.setPosition(-1300,-98);

    Button GAMEOVER("GAMEOVER",{115,50},sf::Color::Red);
    GAMEOVER.setPosition({250,200});
    GAMEOVER.setScale(1,1);

    Button WONGAME("    YOU WON\nSafe Travels Home",{115,50},sf::Color::Green);
    WONGAME.setPosition({250,200});
    WONGAME.setScale(1,1);

    pauseButton.setSize({50,50});
    pauseButton.setPosition({520,5});
    pauseTexture.loadFromFile("Images/Pause.png");
    pauseButton.setTexture(pauseTexture);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            GAMEOVER.enableState(HIDDEN);
            WONGAME.enableState(HIDDEN);

            sf::FloatRect startBound = pauseButton.getGlobalBounds();
            sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& startBound.contains(mPos))
            {
                game.disableState(States::playerMovement);
            }

            if(game.checkState(States::GAMEOVER))
            {
                GAMEOVER.disableState(HIDDEN);
            }
            if(game.checkState(States::PLAYERWIN))
            {
                WONGAME.disableState(HIDDEN);
            }
            mainMenu.addEventHandler(window,event);
            game.addEventHandler(window, event);
        }
        //UPDATES
        mainMenu.update();
        game.update();
        window.clear();
        //MAIN GAME
        window.draw(gameCanvas);
        window.draw(game);
        window.draw(pauseButton);
        window.draw(GAMEOVER);
        window.draw(WONGAME);
        //SPLASH SCREEN
        window.draw(mainMenu);
        window.display();

    }
}
MainGame::~MainGame()
{

}

