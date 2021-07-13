#ifndef SPACEGAME_FONTS_H
#define SPACEGAME_FONTS_H

#include <SFML/Graphics.hpp>

class Fonts
{
private:
    static sf::Font font;
    static bool loaded;
    static void loadFont();
public:
    static sf::Font& getFont();
};


#endif //SPACEGAME_FONTS_H
