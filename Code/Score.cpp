
#include "Score.h"


Score::Score() : Score(0, {0, 0})
{

}

Score::Score(int amount, sf::Vector2f position)
{
    setAmount(amount);
    this->amount.setFont(Fonts::getFont());
    this->amount.setCharacterSize(24);
    this->amount.setFillColor(sf::Color::White);
    this->amount.setScale(.9,.9);

    box.setSize({100, 30});
    box.setFillColor(sf::Color::Transparent);
    Score::setPosition(position);
}

void Score::setAmount(int amount)
{
    this->amount.setString("*" + std::to_string(amount));
}

int Score::getAmount()
{
    std::string s = amount.getString().substring(1);
    return std::stoi(s);
}

void Score::setPosition(sf::Vector2f position)
{
    box.setPosition(position);
    this->amount.setPosition({position.x+5 ,
                              box.getGlobalBounds().top + box.getGlobalBounds().height/2 - this->amount.getGlobalBounds().height/2});
}

void Score::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
    window.draw(amount);
}