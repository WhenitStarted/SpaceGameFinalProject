//
// Created by Nat on 5/30/2021.
//
#ifndef SPACEGAME_STACK_CPP
#define SPACEGAME_STACK_CPP

#include "Stack.h"


template<class t>
Stack<t>::Stack()
{

}
template<class t>
t Stack<t>::pop()
{
//    t temp = list.get_tail();
//    list.remove(list.get_tail());
//    return temp;

    list.pop_back();



}
template<class t>
void Stack<t>::push(t item)
{
    list.push_back(item);
}

template<class t>
t Stack<t>::top()
{
    return list.get_tail();
}

template<class t>
int Stack<t>::size()
{
    return list.size();
}

template<class t>
bool Stack<t>::empty()
{
    return list.empty();
}

template<class S>
std::ostream& operator <<(std::ostream& out, const Stack<S>& stack)
{
    out<<stack.list;
    return out;
}

template<class t>
void Stack<t>::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(list);

}

template<class t>
void Stack<t>::update()
{
    for (int i = 0; i < list.size(); i++)
        list[i].move(2);
}

#endif