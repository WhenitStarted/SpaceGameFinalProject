//
// Created by Nat on 6/6/2021.
//

#include "MainMenu.h"
MainMenu::MainMenu()
:START("START"),EXIT("EXIT"),info(" 0 2021 Nick Teran-CS3A-31195-ALL RIGHTS RESERVED"), HEALTH("HEALTH")
{

    buffer.loadFromFile("Music/Sonic-the-Hedgehog-3-Credits.ogg");
    sound.setBuffer(buffer);
    sound.play();

//    Button START("START",{115,50},sf::Color:: White);
    START.setPosition({100, 400});
    START.setSize({115,50});
    START.setColor(sf::Color::White);
//    START.setScale(1,1);

    EXIT.setPosition({400, 400});
    EXIT.setSize({100,50});
    EXIT.setColor(sf::Color::White);
//    EXIT.setScale(1,1);

    TITLELOGO.loadFromFile("Images/pxArt.png");
    TITLE.setPosition({10, 50});
    TITLE.setSize({612,355});
    TITLE.setTexture(TITLELOGO);
//    TITLE.setScale(1,1);

    info.setPosition({470, 550});
    info.setSize({200,50});
    info.setColor(sf::Color::White);
    info.setScale(.5,.5);

    HEALTH.setPosition({25, 0});
    HEALTH.setSize({115,50});
    HEALTH.setColor(sf::Color::White);
    HEALTH.setScale(.8,.8);


    Instructions.setSize({50,41});
    Instructions.setPosition({15,8});
    InstructText.loadFromFile("Images/Instruction.png");
    Instructions.setTexture(InstructText);

    InstructionTextPopup.loadFromFile("Images/InfoImage.png");
    InstructionPopup.setTexture(InstructionTextPopup);
    InstructionPopup.setSize({520, 520});
    InstructionPopup.setPosition({0, 10});

    texture.loadFromFile("Images/SpashPageIMG.jpg");
    theCanvas.setTexture(texture);
    theCanvas.setSize({650, 650});
    theCanvas.setPosition({0, 0});


}

void MainMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(theCanvas);
    window.draw(START);
    window.draw(EXIT);
    window.draw(TITLE);
    window.draw(info);
    window.draw(InstructionPopup);
    window.draw(Instructions);
}

void MainMenu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    InstructionPopup.enableState(States::HIDDEN);
    sf::FloatRect startBound = START.getGlobalBounds();
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && startBound.contains(mPos) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter ))
    {
                START.enableState(States::HIDDEN);
                EXIT.enableState(States::HIDDEN);
                TITLE.enableState(States::HIDDEN);
                Instructions.enableState(States::HIDDEN);
                theCanvas.enableState(States::HIDDEN);
                InstructionPopup.enableState(States::HIDDEN);
                sound.stop();
    }
    sf::FloatRect instructBound = Instructions.getGlobalBounds();

    if( instructBound.contains(mPos) )
    {
        InstructionPopup.disableState(States::HIDDEN);
    }

    sf::FloatRect exitBound = EXIT.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && exitBound.contains(mPos) )
    {
        window.close();
    }

    START.Button::addEventHandler(window, event);
    EXIT.Button::addEventHandler(window, event);

}

void MainMenu::update()
{
    theCanvas.update();
    START.update();
    EXIT.update();
    TITLE.update();
    info.update();
//    Instructions.update();
//    InstructionPopup.update();

}
