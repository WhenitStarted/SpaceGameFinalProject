//
// Created by Nat on 5/30/2021.
//
#ifndef STACKANDQUE_LINKEDLIST_CPP
#define STACKANDQUE_LINKEDLIST_CPP

#include "LinkedList.h"

template<class t>
void LinkedList<t>::insertBefore(t item, t before)
{
    Node<t>* target =search(before);
    insertBefore(item, target);
}


template<class t>
void LinkedList<t>::insertAfter(t item, t after)
{
    Node<t>* target =search(after);
    insertAfter(item, target);
}

template<class t>
void LinkedList<t>::remove(t item)
{
    Node<t>* target = search(item);
    remove(target);
}

template<class t>
//puts item at the end of the list
void LinkedList<t>::push_back(t item)
{
    Node<t>* newNode =new Node<t>;

    //if the linklist empty
    if(head==nullptr)
    {
        newNode ->data=item;
        newNode->next=nullptr;
        head=newNode;
        tail = newNode;
    }
        // if there is already a node in linked list
    else
    {
        newNode->data=item;
        newNode->next=nullptr;
        tail->next=newNode;
        tail=newNode;
    }
}

//puts item at the begining of the list
template<class t>
void LinkedList<t>::push_front(t item)
{
    Node<t>* newNode =new Node<t>;

    //if the linklist empty
    if(head==nullptr)
    {
        newNode ->data=item;
        newNode->next=nullptr;
        head=newNode;
        tail = newNode;
    }
        // if there is already a node in linked list
    else
    {
        newNode->data=item;
        newNode->next = head;
        head=newNode;
    }
}


template<class t>
int LinkedList<t>::size()
{
    Node<t>* walker=head;
    int counter=0;
    while(walker != nullptr)
    {
        counter++;
        walker=walker->next;
    }
    return counter;
}

// returns true if the linked list is emtpy otherwise false
template<class t>
bool LinkedList<t>::empty()
{
    if(head==nullptr)
        return true;
    return false;
}

template<class S>
std::ostream& operator <<(std::ostream& out,const LinkedList<S>& list)
{
    Node<S>* current = list.head;

    while(current != nullptr)
    {
        out<<current->data<<",";
        current = current->next;
    }
    out<<std::endl;

    return out;
}

//add item to the list linkedlist list; list+=2;
template<class t>
void LinkedList<t>::operator+=(t item)
{
    LinkedList::push_back(item); //DO YOU NEED TO ADD THE "LINKEDLIST::"
}

template<class t>
void LinkedList<t>::insertBefore(t item, Node<t> *target)
{
    Node<t>* temp =new Node<t>;
    //if the linklist empty
    if(head==nullptr)
    {
        temp->data=item;
        temp = head;
        temp = tail;
    }
        // if target the first node
    else if(target == head)
    {
        temp->data=item;
        temp->next = head;
        head = temp;
    }
        //if target the last node in list
    else if(target == tail)
    {
        temp->data=item;
        Node<t>* after=head;
        while(after->next!=tail)
            after = after->next;
        temp->next=after->next;
        after->next=temp;
    }
    else
    {
        Node<t>* prev=head;
        while(prev->next!=target)
        {
            prev = prev->next;
        }
        Node<t>* current=prev->next;
        temp->data=item;
        prev->next=temp;
        temp->next=current;
    }
}

template<class t>
void LinkedList<t>::insertAfter(t item, Node<t> *target)
{
    Node<t>* temp =new Node<t>;

    //if the linklist empty
    if(head==nullptr)
    {
        temp ->data=item;
        temp = head;
        temp = tail;
    }
        // if target the first node
    else if(target == head)
    {
        temp->data=item;
        Node<t>* next = target->next;
        Node<t>* prev = target;
        prev->next = temp;
        temp->next = next;
    }
        //if target the last node in list
    else if(target == tail)
    {
        temp->data=item;
        temp->next=nullptr;
        tail->next=temp;
        tail=temp;
    }
    else
    {
        Node<t>* prev=head;
        while(prev !=target)
        {
            prev = prev->next;
        }
        Node<t>* current=prev->next;
        temp->data=item;
        prev->next=temp;
        temp->next=current;

    }
}

template<class t>
void LinkedList<t>::remove(Node<t> *target)
{

    //if the linklist empty
    if(head==nullptr)
    {
        std::cout<<"Linked List is already empty"<<std::endl;
    }
        // if target the first node
    else if(target == head)
    {

        Node<t>* temp = head;
        head=head->next;
        delete temp;

    }
        //if target the last node in list
    else if(target == tail)
    {
        Node<t>* prev=head;
        while(prev->next != tail)
        {
            prev=prev->next;
        }
        prev->next=nullptr;
        delete target;
        tail= prev;
    }
    else
    {
        Node<t>* prev=head;
        Node<t>* next=target->next;
        while(prev->next !=target)
        {
            prev=prev->next;
//            current = current->next;
        }
        prev->next=next;
        delete target;

    }

}

template<class t>
Node<t>* LinkedList<t>::search(t item)
{
    Node<t>* temp =head;
    while(temp->data != item)
    {
        temp = temp->next;
    }
    return temp;

//    return nullptr;
}

//template<class t>
//LinkedList<t>::LinkedList(const LinkedList &list)
//{
//    *this=list;
//}
//
//template<class t>
//LinkedList<t>::~LinkedList()
//{
//    while(head!=nullptr)
//        remove(head);
//    tail=nullptr;
//}
//
//template<class t>
//LinkedList<t> &LinkedList<t>::operator=(const LinkedList<t> &list)
//{
//    this->LinkedList<t>();
//}

template<class t>
void LinkedList<t>::pop_back()
{
    remove(tail);

//    Node<t> *tmp = head;
//    head = head->next;
//    delete tmp;

}

template<class t>
void LinkedList<t>::pop_front()
{
    remove(head);
}

template<class t>
t LinkedList<t>:: get_tail()
{
    assert(!this->empty());
    return (tail->data);
}

template<class t>
t LinkedList<t>:: get_head()
{
    assert(!this->empty());
    return (head->data);
}

template<class t>
void LinkedList<t>::start()
{
    current = head;
}

template<class t>
bool LinkedList<t>::atEnd()
{
    return current== nullptr && head != nullptr;
}

template<class t>
void LinkedList<t>::forward()
{

    assert(current != nullptr);
    current = current->next;
}

template<class t>
t LinkedList<t>::getCurrentData()
{
    assert(current != nullptr);
    return current->data;
}
template<class t>
void LinkedList<t>::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    Node<t>* current = head;

    while(current != nullptr)
    {
        window.draw(current->data);
        current = current->next;
    }

}

//template<class t>
//void LinkedList<t>::update()
//{
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
//        pop_back();
//
//}

#endif