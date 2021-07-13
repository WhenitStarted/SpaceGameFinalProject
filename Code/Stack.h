//
// Created by Nat on 5/30/2021.
//

#ifndef SPACEGAME_STACK_H
#define SPACEGAME_STACK_H


#include "LinkedList.h"
#include "States.h"
#include <SFML/Graphics.hpp>

template <class t>
class Stack: public sf::Drawable, public sf::Transformable
{

public:
    Stack();
    Stack(int health);

    t pop();//remove item from top
    void push(t item); //Add item to the bottom
    t top();//check item at top
    int size();
    bool empty();
    void sortStack();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update();


    template<class S>
    friend std::ostream& operator <<(std::ostream& out, const Stack<S>& stack);


private:
    LinkedList<t> list;


};

#include "Stack.cpp"

#endif //SPACEGAME_STACK_H
