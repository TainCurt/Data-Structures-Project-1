#include <iostream>
#include "LinkedList.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"

using namespace std;


int main()
{
   DoublyLinkedList LDK;
   LDK.add_first(1);
   LDK.add_first(2);
   LDK.add_first(3);
   LDK.add_first(4);
   LDK.add_first(5);
   LDK.add_first(6);
   LDK.add_back(9);
   LDK.pop_first();
   LDK.pop_back();
   LDK.show();


}
