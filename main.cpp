#include <iostream>
#include "LinkedList.h"
#include "DynamicArray.h"

using namespace std;


int main()
{
    //testuje tablice
    /*
    DynamicArray Array;
    Array.add_first(2);
    Array.add_first(4);
    Array.add_first(5);
    Array.add_first(6);
    Array.add_first(7);
    Array.show();
    std::cout << std::endl;
    Array.add_back(11);
    Array.show();
    std::cout << std::endl;
    Array.pop_first();
    Array.show();
    std::cout << std::endl;
    Array.pop_back();
    Array.show();
    Array.add_first(1);
    Array.add_first(2);
    Array.add_first(3);
    Array.add_first(4);
    Array.add_first(5);
    Array.add_first(6);
    Array.add_first(7);
    Array.add_first(8);
    Array.add_first(9);
    Array.show();
    std::cout << std::endl;
    
    Array.add_at(11111111, 3);
    Array.show();
    std::cout << std::endl;
    Array.pop_at(3);
    Array.show();
    std::cout << std::endl;
    
    if(Array.search(4))
    {
        std::cout<< "true";
        }
        */
       
       LinkedList list;
       list.add_first(3);
       list.add_first(1);
       list.add_first(1);
       list.add_first(1);
       list.add_first(1);
       list.add_first(1);
       list.add_first(1);
       list.add_first(1);
       list.add_first(1);
       list.add_first(2);
       list.add_back(4);
       list.show();

    //std::cout << Array.getsize() << std::endl;
    //std::cout << Array.getcapacity();



}