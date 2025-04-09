#pragma once

class Node // klasa node która jest pomocnicza dla klasy LinkedList
{
public:
    int data;   // przecowuje wartość
    Node *next; // wskaźnik na następny elemnty

    Node() : data(0), next(nullptr) {} // konstruktor
};

class LinkedList
{
private:
    Node *head; // wskaźnik na pierwszy element
    Node *tail; // wskaźnik na ostatni elemnt

public:
    LinkedList();                    // konstruktor domyślny
    ~LinkedList();                   // destruktor
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
