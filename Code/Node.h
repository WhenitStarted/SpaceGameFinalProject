//
// Created by Nat on 5/30/2021.
//

#ifndef SPACEGAME_NODE_H
#define SPACEGAME_NODE_H

#include <SFML/Graphics.hpp>
template<class t>
struct Node
{
    t data;
    Node* next;
    virtual void draw(sf::RenderTarget& window)const
    {
        window.draw(data);
    }
};

#endif //SPACEGAME_NODE_H
