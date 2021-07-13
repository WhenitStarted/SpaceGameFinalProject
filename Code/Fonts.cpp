#include "Fonts.h"
sf::Font Fonts::font;
bool Fonts::loaded = false;
void Fonts::loadFont()
{
    if(!loaded)
    {
        if(!font.loadFromFile("Fonts/INVASION2000.ttf"))
            exit(1);
        loaded = true;
    }

}

sf::Font& Fonts::getFont()
{
    loadFont();
    return font;
}