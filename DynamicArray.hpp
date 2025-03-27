#pragma once

class DynamicArray
{
    private:
    int* array = nullptr;
    int size;
    int capacity;

    
    public:
    DynamicArray();
    DynamicArray(int capacity);
    ~DynamicArray();
    int getsize();
    int getcapacity();
    void add_back();
    void pop_back();
    void add_at();
    void pop_at();
    void add_first();
    void pop_first();
    void doubleArray();
    int search(int number);

};
