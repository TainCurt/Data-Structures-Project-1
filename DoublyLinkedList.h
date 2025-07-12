#pragma once

class Dnode // klasa pomocnicza dla klasy DoublyLinkedList
{
public:
    int data;    // przechowuje wartość
    Dnode *next; // wskaźnik na następny element
    Dnode *prev; // wskaźnik na poprzedni element

    Dnode() : data(0), next(nullptr), prev(nullptr) {} // konstruktor
};

class DoublyLinkedList
{
private:
    Dnode *head; // wskaźnik na pierwszy element
    Dnode *tail; // wskaźnij na ostatni element

public:
    DoublyLinkedList();              // konstruktor domyślny
    ~DoublyLinkedList();             // destruktor
    void add_back(int value);        // dodaje element na koniec listy
    void pop_back();                 // usuwa ostatni element listy
    void add_first(int value);       // dodaje element na początku listy
    void pop_first();                // usuwa pierwszy element listy
    void add_at(int value, int key); // dodaje element na wybranym miejscu listy
    void pop_at(int key);            // usuwa   wybrany element element listy
    bool is_empty();                 // sprawdza czy lista jest pusta
    void search(int value);          // poszukiwanie w listy zadanej wartości
    void show();                     // pokazuje elementy danej listy
    void load();                     // ładuje dane do listy z pliku
    void save();                     // zapisuje dane do pliku
};
