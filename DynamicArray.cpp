#include "DynamicArray.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

DynamicArray::DynamicArray() : capacity(0), size(0), array(nullptr) {} // konstruktor

/*
DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity;
    array = new int[capacity];
    size = 0;
}

*/
DynamicArray::~DynamicArray() // destruktor
{
    delete[] array;
}

int DynamicArray::getcapacity() { return capacity; } // zwraca nam pojemność tablicy

int DynamicArray::getsize() { return size; } // zwraca nam rozmiar tablicy
// funkcja do powiększania tablicy dwukrotnie
void DynamicArray::doubleArray()
{
    capacity = (size == 0) ? 1 : capacity * 2; // warunek sprawdzający czy rozmiar tablicy jest równy 0, jeśli nie to powiększa pojemność dwukrotnie

    // capacity *= 2;
    int *temp = new int[capacity]; // tworzenie nowej tablicy
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i]; // przypisanie elemntów starej tablicy do nowej
    }
    delete[] array; // usunięcie starj tablicy
    array = temp;   // przypisanie nowej tablicy
}
// funckja dodająca element na koniec
void DynamicArray::add_back(int value)
{
    if (size == capacity) // jeśli rozmiar równa się pojemności zwiększ tablice
    {
        doubleArray();
    }

    array[size] = value; // dodaj element na ostatnim indeksie
    size++;              // zwiększ rozmiar tablicy
}
// funckja usuwająca ostatni elemnt tablicy
void DynamicArray::pop_back()
{
    if (size > 0) // jeśli tablica nie jest pusta usuwa ostatni element
    {
        size--;
    }
}
// funckja dodająca element na pierwszym miejscu
void DynamicArray::add_first(int value)
{
    if (size == capacity) // jeśli rozmiar równa się pojemności zwiększ tablice
    {
        doubleArray();
    }

    for (int i = size; i > 0; i--) // przesunięsie wszystkich elemntów o jeden indeks w górę
    {
        array[i] = array[i - 1];
    }
    array[0] = value; // przypisanie wartości na pierwszym miejscy
    size++;
}
// funkcja usuwająca pierwszy element
void DynamicArray::pop_first()
{
    if (size > 0) // jeśli tablica nie jest pusta przypisuje elementom indeks o jeden mniejszy i zmniejsza rozmiar tablicy
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
}
// funckja do wyświetlania
void DynamicArray::show()
{
    for (int i = 0; i < size; i++) // iteruje po całej tablicy i wyświetla dane
    {
        std::cout << " -> " << array[i];
    }
}
// funckja do dodania na wprowadzonym indeksie
void DynamicArray::add_at(int value, int posiotion)
{
    if (size == capacity) // jeśli rozmiar równa się pojemności zwiększ tablice
    {
        doubleArray();
    }

    for (int i = size; i > posiotion - 1; i--) // iteruje od końcu przpyrzpisując elementom indeksy o 1 większy niż obecne do momentu dojścia do miejsca w którym mamy dodać nowy elemnt
    {
        array[i] = array[i - 1];
    }
    array[posiotion - 1] = value;
    size++;
}
// funckja ususwająca element na wprowadzonym indeksie
void DynamicArray::pop_at(int position)
{
    if (size > 0) // jeśli tablica nie jest pusta iteruje od pozycji na której chcemy usunąć i przypisuje od tego miejsca elemntom indeks o jeden mniejszy
    {
        for (int i = position - 1; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
}
// funkcja do wyszukiwania indeksów poszukiwanego elementu
void DynamicArray::search(int value)
{
    vector<int> positions;         // wektor do przechowywania pozycji, gdzie znaleziono wartość
    for (int i = 0; i < size; i++) // iteruje po całej tablicy i jeśli znajdzie dany element zapisuje jego indeks
    {
        if (array[i] == value)
        {
            positions.push_back(i);
        }
    }
    // ten fragment kodu odpowiada za wyświetalnie indeksów na których znajduję poszukiwana wartość
    // na potrzeby testowania ten fragment jest zakomentowany
    /*
    if (positions.empty())
    {}
        cout << "Value " << value << " not found in this list \n";
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

void DynamicArray::load()
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

void DynamicArray::save()
{
    string path;
    cout << "Insert file name: ";
    cin >> path;
    path += ".txt";
    ofstream file(path);
    if (file.is_open())
    {
        for (int i = 0; i < this->getsize(); ++i)
        {
            if (i > 0)
            {
                file << ",";
            }
            file << array[i];
        }
        file.close();
        cout << "Data saved\n";
    }
    else
    {
        cout << "Invalid file\n";
    }
}
