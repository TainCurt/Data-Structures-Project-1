#include "DoublyLinkedList.h" // potrzebne biblioteki
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {} // utworzenie obiektu który nie wskazuje na zaden węzeł

DoublyLinkedList::~DoublyLinkedList() // destruktor
{
    Dnode *temp; // wskaźnik pomocniczy do usuwania węzłów
    while (head) // dopóki lista nie jest pusta
    {
        temp = head;       // zapamiętaj aktualny pierwszy element
        head = head->next; // przesuń wskaźnik na następny element
        delete temp;       // usuń poprzedni pierwszy element
    }
}
// Funkcja sprawdzająca, czy lista jednokierunkowa jest pusta
bool DoublyLinkedList::is_empty()
{
    return head == nullptr; // Zwraca true, jeśli wskaźnik head nie wskazuje na żaden element (czyli lista jest pusta)
}

// Funkcja wyświetlająca zawartość listy dwukierunkowej
void DoublyLinkedList::show()
{
    Dnode *temp = head;     // ustawiamy wskaźnik pomocniczy na początek listy
    while (temp != nullptr) // dopóki nie osiągniemy końca listy
    {
        cout << temp->data << "<->"; // wypisujemy dane z aktualnego węzła
        temp = temp->next;           // przechodzimy do następnego węzła
    }
    cout << "NULL" << endl;
}
// Funkcja dodająca nowy element na początek listy dwukierunkowej
void DoublyLinkedList::add_first(int value)
{
    Dnode *newDnode = new Dnode; // tworzymy nowy węzeł
    newDnode->data = value;      // przypisujemy wartość do pola data
    newDnode->next = head;       // ustawiamy next na dotychczasowy pierwszy element
    newDnode->prev = nullptr;    // ponieważ będzie to pierwszy element, prev to nullptr

    if (is_empty())
    {
        tail = newDnode; // ustawiamy również tail na nowy element jeśli lista jest pusta
    }
    else
    {
        head->prev = newDnode; // jeśli lista nie była pusta, aktualny head wskazuje wstecz na nowy element
    }

    head = newDnode; // przesuwamy head na nowy pierwszy element
}
// Funkcja dodająca nowy element na koniec listy dwukierunkowej
void DoublyLinkedList::add_back(int value)
{
    Dnode *newDnode = new Dnode; // tworzymy nowy węzeł
    newDnode->data = value;      // przypisujemy wartość do pola data
    newDnode->next = nullptr;    // ponieważ to będzie ostatni element, next = nullptr

    if (is_empty())
    {
        newDnode->prev = nullptr; // prev również ustawiamy na nullptr jeśli lista jest pusta
        head = tail = newDnode;   // head i tail wskazują na nowy element
    }
    else
    {
        newDnode->prev = tail; // ustawiamy prev na dotychczasowy ostatni element
        tail->next = newDnode; // dotychczasowy ostatni element wskazuje teraz na nowy
        tail = newDnode;       // przesuwamy tail na nowy ostatni element
    }
}
// Funkcja usuwająca pierwszy element z listy dwukierunkowej
void DoublyLinkedList::pop_first()
{
    if (is_empty()) // jeśli lista jest pusta, nic nie robimy
    {
        return;
    }

    if (head == tail) // jeśli lista zawiera tylko jeden element
    {
        delete head;           // usuwamy ten jedyny element
        head = tail = nullptr; // ustawiamy wskaźniki na nullptr, lista jest teraz pusta
        return;
    }

    Dnode *temp = head;   // zapamiętujemy aktualny pierwszy element
    head = head->next;    // przesuwamy wskaźnik head na kolejny element
    head->prev = nullptr; // nowy pierwszy element nie ma poprzednika
    delete temp;          // usuwamy dawny pierwszy element
}
// Funkcja usuwająca ostatni element z listy dwukierunkowej
void DoublyLinkedList::pop_back()
{
    if (is_empty()) // jeśli lista jest pusta, nic nie robimy
    {
        return;
    }

    if (head == tail) // jeśli lista zawiera tylko jeden element
    {
        delete head;           // usuwamy ten jedyny element
        head = tail = nullptr; // ustawiamy wskaźniki na nullptr, lista jest teraz pusta
        return;
    }

    Dnode *temp = tail->prev; // zapamiętujemy przedostatni element
    temp->next = nullptr;     // nowy ostatni element nie wskazuje na nic z przodu
    delete tail;              // usuwamy obecny ostatni element
    tail = temp;              // przesuwamy tail na nowy koniec listy
}
// Funkcja dodająca nowy element o wartości 'value' na pozycję 'key' (indeks zaczyna się od 1)
void DoublyLinkedList::add_at(int value, int key)
{
    if (key <= 0)
    {
        return;
    }
    else if (key == 1) // jeśli pozycja to 1, dodajemy element na początek
    {
        add_first(value);
        return;
    }

    Dnode *temp = head;               // zaczynamy od początku listy
    for (int i = 1; i < key - 1; i++) // przechodzimy do węzła bezpośrednio poprzedzającego żądaną pozycję
    {
        temp = temp->next;
    }

    Dnode *newNode = new Dnode();
    newNode->data = value;
    if (temp->next) // jeśli istnieje element za miejscem wstawienia
    {
        temp->next->prev = newNode; // ustawiamy jego wskaźnik prev na nowy węzeł
    }
    if (temp == nullptr) // Jeśli nie znaleźliśmy odpowiedniej pozycji (listy jest za mała), usuwamy nowy węzeł i kończymy
    {
        delete newNode; // Usuwamy nowy węzeł, bo nie ma go gdzie dodać
        return;
    }

    newNode->next = temp->next; // nowy węzeł wskazuje na następny element
    temp->next = newNode;       // poprzedni element wskazuje teraz na nowy węzeł
    newNode->prev = temp;       // nowy węzeł wskazuje wstecz na poprzedni element
}
// Funkcja usuwająca element z listy dwukierunkowej na pozycji 'key' (indeks zaczyna się od 1)
void DoublyLinkedList::pop_at(int key)
{
    if (is_empty()) // jeśli lista jest pusta, nic nie robimy
    {
        return;
    }

    if (key < 0) // jeśli podany indeks jest niepoprawny (ujemny), przerywamy
    {
        return;
    }

    if (key == 1) // usuwanie pierwszego elemntu
    {
        pop_first();
        return;
    }

    Dnode *temp = head;
    int i = 1;

    while (temp != nullptr && i < key - 1) // Przechodzimy do węzła poprzedzającego węzeł do usunięcia
    {
        temp = temp->next;
        i++;
    }
    Dnode *toDelete = temp->next; // węzeł, który chcemy usunąć
    temp->next = toDelete->next;  // wskazujemy na następny węzeł po tym, który usuwamy
    if (toDelete->next)           // jeśli za usuwanym węzłem znajduje się jeszcze węzeł
    {
        toDelete->next->prev = temp; // ustawiamy wskaźnik prev dla nowego węzła na poprzedni węzeł
    }
    delete toDelete; // usuwamy węzeł
}

void DoublyLinkedList::search(int value)
{
    Dnode *temp = head;         // zaczynamy od początku listy
    std::vector<int> positions; // wektor do przechowywania pozycji, gdzie znaleziono wartość
    int index = 0;

    while (temp != nullptr) // Przechodzimy po wszystkich węzłach listy
    {
        if (temp->data == value) // jeśli wartość w bieżącym węźle jest równa szukanej
        {
            positions.push_back(index); // dodajemy indeks do wektora 'positions'
        }
        temp = temp->next; // przechodzimy do następnego węzła
        index++;           // inkrementujemy indeks
    }
    // ten fragment kodu odpowiada za wyświetalnie indeksów na których znajduję poszukiwana wartość
    // na potrzeby testowania ten fragment jest zakomentowany
    /*
    if (positions.empty())
    {
         cout << "Value " << value << " not found in this list.\n";
    }
    else
    {
        cout << "Value " << value << " found at positions:\n";
        for (int pos : positions)
        {
            cout << pos << " ";
        }
        cout << std::endl;
    }
    */
}

void DoublyLinkedList::load()
{
    string path;
    cout << "Insert file name: ";
    cin >> path;
    path += ".txt";
    ifstream file(path);
    string data;
    if (file.is_open())
    {
        getline(file, data);
        stringstream ss(data);
        string val;

        while (getline(ss, val, ','))
        {
            int number = stoi(val);
            this->add_back(number);
        }
    }
    else
    {
        cout << "Invalid file\n";
    }
}
void DoublyLinkedList::save()
{
    string path;
    cout << "Insert file name: ";
    cin >> path;
    path += ".txt";
    ofstream file(path);
    if (file.is_open())
    {
        Dnode *temp = head;
        while (temp->next != nullptr)
        {
            file << temp->data;
            if (temp->next != nullptr)
            {
                file << ",";
            }
            temp = temp->next;
        }
        file.close();
        cout << "Data saved\n";
    }
    else
    {
        cout << "Invalid file\n";
    }
}
