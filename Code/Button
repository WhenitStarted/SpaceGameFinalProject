#include "Button.h"

Button::Button() : Button("Text")
{

}
Button::Button(std::string text, sf::Vector2f size, sf::Color color) : color(color)
{
    this->text.setString(text);
//    this->text.setScale({5, 5});
    background.setSize(size);
    background.setFillColor(sf::Color::Transparent);
   this->text.setFillColor(color);
    initialize();
}
Button::Button(std::string text) : Button(text, {100, 50}, sf::Color::White)
{

}

void Button::center()
{
    sf::FloatRect bBounds = background.getGlobalBounds();
    sf::FloatRect tBounds = text.getGlobalBounds();

    text.setPosition(bBounds.left + bBounds.width/2 - tBounds.width/2,
                     bBounds.top +bBounds.height/2 - tBounds.height );
}
void Button::initialize()
{
    text.setFont(Fonts::getFont());
//    text.setScale(.5,.5);
    center();


}


//polymorphism, you can see this by holding command (control) and clicking on the class name
void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    // states.transform = getTransform();
    if(!checkState(HIDDEN))
    {
        window.draw(background, states);
        window.draw(text, states);
//        std::cout << background.getGlobalBounds().left << ", " << background.getGlobalBounds().top << std::endl;
    }

}

//event handler
void Button::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    hover(window, event);

}

//make any necessary updates
void Button::update()
{
//IF YOU WANT BUTTON TO CHANGE COLOR THEN USE THE CODE THAT IS BELOW//
//    if(checkState(HOVERED))
//        background.setFillColor(sf::Color::Blue);
//    if(checkState(NORMAL))
//        background.setFillColor(color);
    if(checkState(HOVERED))
    {
        text.setFillColor(sf::Color::Red);
    }

    if(checkState(NORMAL))
        text.setFillColor(color);
}

bool Button::hover(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect bBounds = background.getGlobalBounds();
    sf::FloatRect tBounds = text.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>( sf::Mouse::getPosition(window));
    if(tBounds.contains(mPos))
    {
        enableState(HOVERED);
        disableState(NORMAL);
        return true;
    }

    else
    {
        enableState(NORMAL);
        disableState(HOVERED);
        return false;
    }

//    if(bBounds.contains(mPos))
//    {
//        enableState(HOVERED);
//        disableState(NORMAL);
//        return true;
//    }
//
//    else
//    {
//        enableState(NORMAL);
//        disableState(HOVERED);
//        return false;
//    }


}


sf::FloatRect Button::getGlobalBounds()
{
    return background.getGlobalBounds();
}

void Button::setPosition(sf::Vector2f position)
{
//    background.setPosition(position);
//    center();
    sf::Transformable::setPosition(position);
    sf::Vector2f bBounds = background.getPosition();
    sf::Vector2f tBounds = text.getPosition();
    background.setPosition(sf::Transformable::getTransform().transformPoint(bBounds));
    text.setPosition(sf::Transformable::getTransform().transformPoint(tBounds));
}

void Button::setScale (float factorX, float factorY)
{
    text.setScale(factorX,factorY);
}

void Button::setSize(const sf::Vector2f &size) {
    Button::size = size;
}

void Button::setColor(const sf::Color &color)
{
    text.setFillColor(color);
}

