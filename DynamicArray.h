#pragma once

class DynamicArray
{
private:
    int *array = nullptr; // wskaźnik na dynamicznie alokowaną tablicę
    int size;             // aktualny rozmiar tablicy (ilość elementów)
    int capacity;         // pojemność tablicy (maksymalna ilość przed rozszerzeniem)

public:
    DynamicArray(); // konstruktor
    // DynamicArray(int capacity);
    ~DynamicArray();                      // destruktor
    int getsize();                        // metody getsize oraz getcapacity przydatne podaczas testowana czy inne metody działają
    int getcapacity();                    //
    void add_back(int value);             // dodaje element na koniec tablicy
    void pop_back();                      // usuwa ostatni element tablicy
    void add_first(int value);            // dodaje element na początku tablicy
    void pop_first();                     // usuwa pierwszy element tablicy
    void add_at(int value, int position); // dodaje element na wybranym miejscu tablicy
    void pop_at(int position);            // usuwa   wybrany element element tablicy
    void doubleArray();                   // metoda który służy do zwiększenia rozmiaru tablicy dwukrotnie w razie braku miejsca
    void search(int value);               // poszukiwanie w tablicy zadanej wartości
    void show();                          // pokazuje elementy danej tablicy
    void load();                          // ładuje dane do tablicy z pliku
    void save();                          // zapisuje dane do pliku
};
