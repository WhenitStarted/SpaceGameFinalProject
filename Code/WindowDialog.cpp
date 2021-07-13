
#include "WindowDialog.h"


WindowDialog::WindowDialog() : WindowDialog("Success!")
{

}
WindowDialog::WindowDialog(std::string displayText) : window({500, 500, 32}, "Display Dialog")
{
    this->displayText.setFont(Fonts::getFont());
    this->displayText.setString(displayText);
    window.close();

}


void WindowDialog::run()
{
    window.create({500, 500, 32}, "Display Dialog");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(displayText);
        window.display();
    }
}
