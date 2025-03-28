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


void LinkedList::add_back(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::pop_back()
{
    Node* temp = head;
    while(temp->next != tail )
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
}


void LinkedList::add_at(int value, int key)
{
    if (key <= 0) {
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (key == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int i = 1;

    while (temp != nullptr && i < key - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

