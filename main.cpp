#include <iostream>
#include "LinkedList.h"
#include "DynamicArray.h"

using namespace std;


int main()
{
    //testuje tablice
    DynamicArray Array;
   Array.add_first(2);
    Array.add_first(3);
    Array.add_first(3);
    Array.add_first(3);
    Array.add_first(3);
   //Array.show();
    std::cout << Array.getsize() << std::endl;
    std::cout << Array.getcapacity();



}