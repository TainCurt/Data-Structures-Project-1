#pragma once

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
    private:
    Node* head;

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
    bool search();
    void show();


};


