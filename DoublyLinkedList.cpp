#include "DoublyLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
    Dnode* temp;
    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    
}

bool DoublyLinkedList::is_empty()
{
   return head == nullptr;
}


void DoublyLinkedList::show()
{
    Dnode* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void DoublyLinkedList::add_first(int value)
{
    Dnode* newDnode = new Dnode;
    newDnode->data = value;
    newDnode->next = head;
    newDnode->prev = nullptr;

    if (is_empty())
    {
        tail = newDnode;
    }
    else
    {
        head->prev = newDnode;
    }
    
    head = newDnode;
}



void DoublyLinkedList::add_back(int value)
{
    Dnode* newDnode = new Dnode;
    newDnode->data = value;
    newDnode->next = nullptr;

    if (is_empty())
    {
        newDnode->prev = nullptr;
        head = tail = newDnode;
    }
    else
    {
        newDnode->prev = tail;
        tail->next = newDnode;
        tail = newDnode;
    }
    
}


/*
void DoublyLinkedList::pop_back()
{
    
}

*/