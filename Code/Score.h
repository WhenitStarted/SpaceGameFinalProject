
#ifndef SPACEGAME_SCORE_H
#define SPACEGAME_SCORE_H

#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Score : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape box;
    sf::Text amount;
public:
    Score();
    Score(int amount, sf::Vector2f position);
    void setAmount(int amount);
    int getAmount();
    void setPosition(sf::Vector2f position);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //SPACEGAME_SCORE_H
