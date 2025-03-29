#include "LinkedList.h"
#include <iostream>
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
   return head == nullptr;
}

void LinkedList::add_first(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) { // Jeśli lista była pusta, ustaw również tail
        tail = head;
    }

}

void LinkedList::show(){
    Node* temp = head;
    while(temp != nullptr){
      std::cout << temp->data << "->";
      temp = temp->next;
    }
    std::cout << "NULL" <<std::endl;
}

void LinkedList::pop_first()
{
     
    Node* temp = head;
    head = head->next;
    delete temp;
    if(is_empty())
    {
        tail = nullptr;
    }
}


void LinkedList::add_back(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if(is_empty())
    {
        head = tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

void LinkedList::pop_back()
{

    if(is_empty())
    {
        return;
    }

    if(head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

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

void LinkedList::pop_at(int key) //chyba działa, sprawdź 
{
    if(is_empty());

    if(key < 0)
    {
        return;
    }

    if (key == 1)
    {
      pop_first();
      return;
    }
    
    
    Node* temp = head;
    int i = 1;

    while (temp != nullptr && i < key - 1) {
        temp = temp->next;
        i++;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail)
    {
        tail = temp;
    }
    
    delete toDelete;

}
