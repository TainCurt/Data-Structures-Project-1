#pragma once
#include <iostream>

class Node {
private:
	int data;
	Node* prev;
	Node* next;
	friend class DoublyLinked;

	Node() : data(0), next(nullptr), prev(nullptr) {}
};

class DoublyLinked{
private:
	Node* header;
	Node* trailer;

public:
	DoublyLinked();
	~DoublyLinked();
	bool empty() const;
	const int& front() const;
	const int& back() const;
	void addFront(const int data);
	void addBack(const int data);
	void removeFront();
	void removeBack();
	void show();

protected:
	void add(Node* v, const int& d);
	void remove(Node* v);
};