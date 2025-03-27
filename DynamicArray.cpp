#include "DynamicArray.hpp"

DynamicArray::DynamicArray() : capacity(0), size(0), array(nullptr) {}

DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity;
    array = new int[capacity];
    size = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] array;
}

int DynamicArray::getcapacity() { return capacity; }

int DynamicArray::getsize() { return size; }

void DynamicArray::doubleArray()
{
    capacity *= 2;
    int* temp = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array [i];
    }
    delete[] array;
    array = temp;
    
}

void DynamicArray::add_back(int value)
{
    if(size == capacity)
    {
        doubleArray();
    }

    size++;
    array[size] = value;
}

void DynamicArray::pop_back()
{
    if(size > 0)
    {
        size--;
    }
}

void DynamicArray::add_first(int value)
{
    if(size == capacity)
    {
        doubleArray();
    }

    if (size == 0)
    {
        array[0] = value;
        size++;
    }

    for (int i = size; i < 0; i--)
    {
        array[i] = array[i-1];
    }
    array[0] = value;
    size++;
    
}

