#pragma once

class Dnode
{
    public:
    int data;
    Dnode* next;
    Dnode* prev;

    Dnode() : data(0), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList 
{
    private:
    Dnode* head;
    Dnode* tail;

    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add_back(int value);
    void pop_back();
    void add_first(int value);
    void pop_first();
    void add_at(int value, int key);
    void pop_at(int key);
    bool is_empty();
    bool search(int value);
    void show();


};


