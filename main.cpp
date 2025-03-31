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
   LDK.add_first(3);
   LDK.add_first(3);
   LDK.add_first(3);
   LDK.add_back(9);
   LDK.show();


}
