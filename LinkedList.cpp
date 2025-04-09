#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {} // Inicjalizujemy wskaźniki head i tail na nullptr,

LinkedList::~LinkedList() // Destruktor
{
    Node *temp;
    while (head) // Pętla usuwa wszystkie węzły w liście
    {
        temp = head;       // Zapamiętujemy obecny pierwszy węze
        head = head->next; // Przechodzimy do kolejnego węzła
        delete temp;       // Usuwamy zapamiętany węzeł
    }
}
// Funkcja sprawdzająca, czy lista jest pusta
bool LinkedList::is_empty()
{
    return head == nullptr; // Funkcja sprawdzająca, czy lista jest pusta
}
// Funkcja dodająca nowy element na początek listy
void LinkedList::add_first(int value)
{
    Node *newNode = new Node; // Tworzymy nowy węzeł
    newNode->data = value;    // Przypisujemy wartość do nowego węzła
    newNode->next = head;     // Nowy węzeł wskazuje na dotychczasowy pierwszy węzeł
    head = newNode;           // Ustawiamy wskaźnik head na nowy węzeł

    if (tail == nullptr) // Jeśli lista była pusta, ustaw również tail
    {
        tail = head;
    }
}
// Funkcja wyświetlająca zawartość listy jednokierunkowej
void LinkedList::show()
{
    Node *temp = head;      // ustawiamy wskaźnik pomocniczy na początek listy
    while (temp != nullptr) // dopóki nie osiągniemy końca listy
    {
        cout << temp->data << "->"; // wypisujemy dane z aktualnego węzła
        temp = temp->next;          // przechodzimy do następnego węzła
    }
    cout << "NULL" << std::endl;
}
// Funkcja usuwająca pierwszy element z listy jednokierunkowej
void LinkedList::pop_first()
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

    Node *temp = head; // zapamiętujemy aktualny pierwszy element
    head = head->next; // przesuwamy wskaźnik head na kolejny elemen
    delete temp;       // usuwamy dawny pierwszy element
}
// Funkcja dodająca nowy element na koniec listy jednokierunkowej
void LinkedList::add_back(int value)
{
    Node *newNode = new Node; // tworzymy nowy węzeł
    newNode->data = value;
    newNode->next = nullptr;
    if (is_empty()) // jeśli lista jest pusta
    {
        head = tail = newNode; // head i tail wskazują na nowy element
    }
    tail->next = newNode; // dotychczasowy ostatni element wskazuje teraz na nowy
    tail = newNode;       // przesuwamy tail na nowy ostatni element
}
// Funkcja usuwająca ostatni element z listy jednokierunkowej
void LinkedList::pop_back()
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

    Node *temp = head;         // Zaczynamy od początku listy
    while (temp->next != tail) // Przechodzimy do węzła, który poprzedza ostatni element
    {
        temp = temp->next;
    }
    delete tail;          // Usuwamy ostatni węzeł (tail)
    tail = temp;          // Przesuwamy wskaźnik tail na poprzedni węzeł (teraz to nowy ostatni element)
    tail->next = nullptr; // Ustawiamy wskaźnik next na nullptr, ponieważ teraz to ostatni węzeł
}
// Funkcja dodająca nowy element o wartości 'value' na określoną pozycję 'key'
void LinkedList::add_at(int value, int key) // jeśli podana pozycja jest ujemna, przerywamy (błędny indeks)
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

    Node *newNode = new Node; // Tworzymy nowy węzeł
    newNode->data = value;    // Przypisujemy wartość do nowego węzła
    newNode->next = nullptr;  // Nowy węzeł nie wskazuje na nic, ponieważ będziemy go wstawiać w środek listy

    Node *temp = head; // Zaczynamy od początku listy
    int i = 1;

    while (temp != nullptr && i < key - 1) // Przechodzimy do węzła poprzedzającego węzeł do usunięcia
    {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) // Jeśli nie znaleźliśmy odpowiedniej pozycji (listy jest za mała), usuwamy nowy węzeł i kończymy
    {
        delete newNode; // Usuwamy nowy węzeł, bo nie ma go gdzie dodać
        return;
    }

    newNode->next = temp->next; // Nowy węzeł wskazuje na węzeł, który był za temp
    temp->next = newNode;       // Węzeł temp teraz wskazuje na nowy węzeł
}

void LinkedList::pop_at(int key)
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

    Node *temp = head;
    int i = 1;

    while (temp != nullptr && i < key - 1) // Przechodzimy do węzła poprzedzającego węzeł do usunięcia
    {
        temp = temp->next;
        i++;
    }

    Node *toDelete = temp->next; // węzeł, który chcemy usunąć
    temp->next = toDelete->next; // wskazujemy na następny węzeł po tym, który usuwamy
    if (toDelete == tail)        // Jeśli usuwamy ostatni element, to aktualizujemy wskaźnik 'tail'
    {
        tail = temp;
    }

    delete toDelete; // Usuwamy węzeł
}

void LinkedList::search(int value)
{
    Node *temp = head;          // zaczynamy od początku listy
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
        // cout << "Value " << value << " not found in this list.\n";
    }
    else
    {
        cout << "Value " << value << " found at positions:\n";
        for (int pos : positions)
        {
            cout << pos << " ";
        }
        cout << endl;
    }
    */
}

void LinkedList::load()
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
void LinkedList::save()
{
    string path;
    cout << "Insert file name: ";
    cin >> path;
    path += ".txt";
    ofstream file(path);
    if (file.is_open())
    {
        Node *temp = head;
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
