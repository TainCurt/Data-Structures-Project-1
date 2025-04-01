#include "DoublyLinked.h"
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

bool DoublyLinked::empty() const{
	return (header -> next == trailer);
}

const int& DoublyLinked::front() const {
	return header -> next->data;
}

const int& DoublyLinked::back() const {
	return trailer->prev->data;
}

void DoublyLinked::addFront(const int data){
	add(header -> next, data);
}

void DoublyLinked::addBack(const int data) {
	add(trailer -> prev, data);
}

void DoublyLinked::removeFront() {
	remove(header -> next);
}

void DoublyLinked::removeBack() {
	remove(trailer -> prev);
}

void DoublyLinked::show() {
	Node* temp = header;
	while (temp != nullptr) {
		cout << temp -> data << "->";
		temp = temp -> next;
	}
	cout << "NULL" << endl;
}

void DoublyLinked::add(Node* v, const int& d) {
	Node* u = new Node;
	u->data = d;
	u->next = v;
	u->prev->next = v->prev = u;
	v -> prev -> next = v -> prev = u;
}

void DoublyLinked::remove(Node* v) { 
	Node* u = v -> prev; 
	Node* w = v -> next; 
	u -> next = w;
	w -> prev = u;
	delete v;
}

int main() {
	DoublyLinked* list = new DoublyLinked();
	~DoublyLinked();

	return 0;
}