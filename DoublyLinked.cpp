#include "DoublyLinked.h"
#include <iostream>
using namespace std;

DoublyLinked::DoublyLinked() {
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

DoublyLinked::~DoublyLinked() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DoublyLinked::empty() const {
    return (header->next == trailer);
}

const int& DoublyLinked::front() const {
    if (empty()) {
        throw runtime_error("List is empty");
    }
    return header->next->data;
}

const int& DoublyLinked::back() const {
    if (empty()) {
        throw runtime_error("List is empty");
    }
    return trailer->prev->data;
}

void DoublyLinked::addFront(const int data) {
    add(header->next, data);
}

void DoublyLinked::addBack(const int data) {
    add(trailer, data); // Fixed: Adding before `trailer`
}

void DoublyLinked::removeFront() {
    if (!empty()) {
        remove(header->next);
    } else {
        cout << "List is already empty!" << endl;
    }
}

void DoublyLinked::removeBack() {
    if (!empty()) {
        remove(trailer->prev);
    } else {
        cout << "List is already empty!" << endl;
    }
}

void DoublyLinked::show() {
    Node* temp = header->next;
    while (temp != trailer) {  // Fixed: Check against `trailer`
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DoublyLinked::add(Node* v, const int& d) {
    Node* u = new Node;
    u->data = d; // Fixed: Assign data
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}

void DoublyLinked::remove(Node* v) {
    if (v == header || v == trailer) return; // Prevent removing dummy nodes
    Node* u = v->prev;
    Node* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}
