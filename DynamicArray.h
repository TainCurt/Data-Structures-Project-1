#pragma once

class DynamicArray
{
    private:
    int* array = nullptr;
    int size;
    int capacity;

    
    public:
    DynamicArray();
   // DynamicArray(int capacity);
    ~DynamicArray();
    int getsize();
    int getcapacity();
    void add_back(int value);
    void pop_back();
    void add_first(int value);
    void pop_first();
    void add_at(int value, int position);
    void pop_at(int position);
    void doubleArray();
    void search(int value);
    void show();
};
