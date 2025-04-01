#include <iostream>
//#include "LinkedList.h"
//#include "DynamicArray.h"
#include "DoublyLinkedList.h"
//#include "DoublyLinked.h"


using namespace std;


int main()
{
   DoublyLinkedList list;
   list.add_first(1);
   list.add_first(2);
   list.add_first(3);
   list.add_first(4);
   list.add_first(5);
   list.add_first(6);
   list.add_first(7);
   list.add_first(8);
   list.add_first(9);
   list.show();
   //list.add_at(100000, 4);
   list.pop_at(3);
   list.show();




}
