

#ifndef SPACEGAME_MAINMENU_H
#define SPACEGAME_MAINMENU_H
#include "Button.h"
#include "Rectangle.h"
#include <SFML/Audio.hpp>

class MainMenu: public sf::Drawable, public sf::Transformable
{
private:
    Button START, info, EXIT,HEALTH;
    Rectangle theCanvas,Instructions,InstructionPopup,TITLE;
    sf::Texture texture,InstructText,InstructionTextPopup,TITLELOGO;
    sf::Sound sound;
    sf::SoundBuffer buffer;

public:
    MainMenu();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SPACEGAME_MAINMENU_H
