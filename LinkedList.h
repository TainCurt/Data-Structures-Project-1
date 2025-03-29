#pragma once

class Node
{
    public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head;
    Node* tail;

    public:
    LinkedList();
    ~LinkedList();
    void add_back(int value);
    void pop_back();
    void add_first(int value);
    void pop_first();
    void add_at(int value, int key);
    void pop_at(int key);
    bool is_empty();
    void show();

};