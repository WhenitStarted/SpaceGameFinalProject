//
// Created by Nat on 5/23/2021.
//

#ifndef SPACEGAME_WINDOWDIALOG_H
#define SPACEGAME_WINDOWDIALOG_H

#include <SFMl/Graphics.hpp>
#include "Fonts.h"
class WindowDialog
{

private:
    sf::RenderWindow window;
    sf::Text displayText;

public:
    WindowDialog();
    WindowDialog(std::string displayText);

    void run();

};

#endif //SPACEGAME_WINDOWDIALOG_H
