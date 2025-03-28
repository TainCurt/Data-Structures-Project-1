#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList()
{
    Node* temp;
    while (head) 
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::is_empty()
{
    if (head == nullptr)
    {
        return 1;
    }
    
}

void LinkedList::add_first(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

}


void LinkedList::pop_first()
{
    Node* temp = head;
    head = temp->next;
    delete temp;
}


