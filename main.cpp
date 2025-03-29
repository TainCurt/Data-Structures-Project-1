#include <iostream>
#include "LinkedList.h"


using namespace std;


int main()
{
    LinkedList lita;
    lita.add_first(5);
    lita.add_first(2);

    lita.add_first(3);
    lita.add_back(1);
    lita.add_at(10, 2);
    lita.show();
    lita.pop_at(3);
    lita.pop_at(4);

    lita.show();
}