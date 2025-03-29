#include <iostream>
#include "LinkedList.h"


using namespace std;


int main()
{

    //testy listy
    LinkedList lista;
    srand(time(NULL));
    
    for (int i = 0; i < 100; i++)
    {
        int r = rand() % 100;
        lista.add_first(r);
    }
    lista.show();
    std::cout << std::endl << std::endl << std::endl;
    lista.pop_back();
    lista.show();
}