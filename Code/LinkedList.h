//
// Created by Nat on 5/30/2021.
//

#ifndef SPACEGAME_LINKEDLIST_H
#define SPACEGAME_LINKEDLIST_H




#include "Node.h"
#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

template<class t>

class LinkedList:public sf::Drawable, public sf::Transformable
{
public:
    void insertBefore(t item, t before);
    void insertAfter(t item,t after);
    void remove(t item);
    void push_back(t item);
    void push_front(t item);
    int size();
    bool empty();
    void operator +=(t item);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();

    //USED FOR STACK AND QUE
    void pop_back();
    void pop_front();
    t get_tail();
    t get_head();

    void start();
    bool atEnd();
    void forward();
    t getCurrentData();



//    NEED TO CHECK THIS
//    LinkedList(const LinkedList& list);
//    ~LinkedList();
//    LinkedList<t>& operator =(const LinkedList<t>& list);


    template<class S>
    friend std::ostream& operator <<(std::ostream& out, const LinkedList<S>& list);


private:
    Node<t>* head = nullptr;
    Node<t>* tail = nullptr;
    Node<t>* current = nullptr;
    void insertBefore(t item, Node<t>* target);
    void insertAfter(t item, Node<t>* target);
    void remove(Node<t>* target);
    Node<t>* search(t item); //int item, returns Nod*;


};

#include "LinkedList.cpp"

#endif //SPACEGAME_LINKEDLIST_H
