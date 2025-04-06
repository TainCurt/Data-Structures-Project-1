#include "DoublyLinkedList.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
    Dnode *temp;
    while (head)
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
    Dnode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DoublyLinkedList::add_first(int value)
{
    Dnode *newDnode = new Dnode;
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
    Dnode *newDnode = new Dnode;
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

void DoublyLinkedList::pop_first()
{
    if (is_empty())
    {
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Dnode *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

void DoublyLinkedList::pop_back()
{
    if (is_empty())
    {
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Dnode *temp = tail->prev;
    temp->next = nullptr;
    delete tail;
    tail = temp;
}

void DoublyLinkedList::add_at(int value, int key)
{
    if (key < 0)
    {
        return;
    }

    if (key == 1)
    {
        add_first(value);
        return;
    }

    Dnode *temp = head;
    for (int i = 1; i < key - 1; i++)
    {
        temp = temp->next;
    }

    Dnode *newNode = new Dnode();
    newNode->data = value;
    if (temp->next)
    {
        temp->next->prev = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::pop_at(int key)
{
    if (is_empty())
    {
        return;
    }

    if (key < 0)
    {
        return;
    }

    if (key == 1)
    {
        pop_first();
        return;
    }

    Dnode *temp = head;
    int i = 1;

    while (temp != nullptr && i < key - 1)
    {
        temp = temp->next;
        i++;
    }
    Dnode *toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next)
    {
        toDelete->next->prev = temp;
    }
    delete toDelete;
}

void DoublyLinkedList::search(int value)
{
    Dnode *temp = head;
    std::vector<int> positions;
    int index = 0;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            positions.push_back(index);
        }
        temp = temp->next;
        index++;
    }

    if (positions.empty())
    {
        // cout << "Value " << value << " not found in this list.\n";
    }
    else
    {
        /*
        cout << "Value " << value << " found at positions:\n";
        for (int pos : positions)
        {
            cout << pos << " ";
        }
        cout << std::endl;
        */
    }
}
