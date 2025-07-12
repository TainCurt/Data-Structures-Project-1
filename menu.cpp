#include <iostream>
#include <chrono>
#include <numeric>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;

void menu()
{
    // Inicjacja zmiennych oraz list tymczasowych
    int list, operation, val, place;
    char cont;
    unique_ptr<DynamicArray> dynList = make_unique<DynamicArray>();
    unique_ptr<LinkedList> linkedList = make_unique<LinkedList>();
    unique_ptr<DoublyLinkedList> doubleList = make_unique<DoublyLinkedList>();

    // Tworzenie tekstowego interfejsu dla menu wraz z przekazywaniem wyborów do zmiennych
    cout << "Select type of list to operate on: \n"
            "1. Dynamic List\n"
            "2. Linked List\n"
            "3. Doubly Linked List\n";
    cin >> list;
    while (true)
    { // Lista operacji do wykoniania na liście pokazuje się do czasu chęci zakończenia pracy przez użytkownika
        cout << "\nSelect operation:\n"
                "1. Add value to the start of list\n"
                "2. Add value to the end of list\n"
                "3. Add value at the selected place in the list\n"
                "4. Remove the first value from the list\n"
                "5. Remove the last value from the list\n"
                "6. Remove the selected value from the list\n"
                "7. Search positions of the given value in list\n"
                "8. Load data from the preselected file\n"
                "9. Save data to the preselected file\n";
        cin >> operation;

        // Dla operacji 1-3 i 7 wymagany jest argument value
        if (operation >= 1 && operation <= 3 || operation == 7)
        {
            cout << "Enter value: ";
            cin >> val;
            if (operation == 3)
            { // Dla operacji 3 dodatkowo wymagana jest pozycja
                cout << "Enter position: ";
                cin >> place;
            }
        }
        if (operation == 6)
        { // Dla operacji 6 wymagana jest tylko pozycja
            cout << "Enter position: ";
            cin >> place;
        }
        if (operation < 1 || operation > 9)
        { // Jeżeli została wybrana inna operacja niż 1-9 wyświetli ponownie listę operacji
            cout << "Invalid operation.\n";
            continue;
        }
        // Wywoływanie metod przypisanych do wyboru użytkownika
        switch (list)
        {
        case 1:
            switch (operation)
            {
            case 1:
                dynList->add_first(val);
                break;
            case 2:
                dynList->add_back(val);
                break;
            case 3:
                dynList->add_at(val, place);
                break;
            case 4:
                dynList->pop_first();
                break;
            case 5:
                dynList->pop_back();
                break;
            case 6:
                dynList->pop_at(place);
                break;
            case 7:
                dynList->search(val);
                break;
            case 8:
                dynList->load();
                break;
            case 9:
                dynList->save();
                break;
            default:
                cout << "Invalid operation.\n";
            }
            break;
        case 2:
            switch (operation)
            {
            case 1:
                linkedList->add_first(val);
                break;
            case 2:
                linkedList->add_back(val);
                break;
            case 3:
                linkedList->add_at(val, place);
                break;
            case 4:
                linkedList->pop_first();
                break;
            case 5:
                linkedList->pop_back();
                break;
            case 6:
                linkedList->pop_at(place);
                break;
            case 7:
                linkedList->search(val);
                break;
            case 8:
                linkedList->load();
                break;
            case 9:
                linkedList->save();
                break;
            default:
                cout << "Invalid operation.\n";
            }
            break;
        case 3:
            switch (operation)
            {
            case 1:
                doubleList->add_first(val);
                break;
            case 2:
                doubleList->add_back(val);
                break;
            case 3:
                doubleList->add_at(val, place);
                break;
            case 4:
                doubleList->pop_first();
                break;
            case 5:
                doubleList->pop_back();
                break;
            case 6:
                doubleList->pop_at(place);
                break;
            case 7:
                doubleList->search(val);
                break;
            case 8:
                doubleList->load();
                break;
            case 9:
                doubleList->save();
                break;
            default:
                cout << "Invalid operation.\n";
            }
            break;
        default:
            cout << "Invalid list selection.\n";
        }
        // Po każdej operacji możemy wyświetlić listę, wielkość litery nie ma znacznia
        cout << "\nDo you want to display this list? (y/n): ";
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
        {
            switch (list)
            { // Automatycznie wybiera listę do wyświetlenia
            case 1:
                dynList->show();
                break;
            case 2:
                linkedList->show();
                break;
            case 3:
                doubleList->show();
                break;
            }
        }
        // Możliwość zakończenia pracy programu
        cout << "\nDo you want to continue with this list? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
        {
            cout << "Exiting list operation menu. . .\n";
            break;
        }
    }
}
