#include "List.h"

#include <iostream>

using namespace std;

template <typename T>
Node<T>::Node(T data) {
	this->Data = data;
	this->Prev = this->Next = nullptr;
}

template <typename T>
List<T>::List() {
	this->head = this->tail = nullptr;
}

template <typename T>
Node<T>* List<T>::Iterator() {
	return this->head;
}

template <typename T>
Node<T>* List<T>::PushBack(T data) {
	Node<T>* newNode = new Node<T>(data);

	if (IsEmpty()) {
		this->head = this->tail = newNode;
	}
	else {
		this->tail->Next = newNode;
		newNode->Prev = this->tail;
		this->tail = newNode;
	}

	return newNode;
}

template <typename T>
void List<T>::PopBack() {
	if (IsEmpty()) {
		return;
	}

	Node<T>* prev = this->tail->Prev;

	if (prev != nullptr) {
		prev->Next = nullptr;
	}
	else {
		this->head = nullptr;
	}

	delete this->tail;
	this->tail = prev;
}

template <typename T>
Node<T>* List<T>::PushFront(T data) {
	Node<T>* newNode = new Node<T>(data);

	if (IsEmpty()) {
		this->head = this->tail = data;
	}
	else {
		this->head->Prev = newNode;
		newNode->Next = this->head;
		this->head = newNode;
	}

	return newNode;
}

template <typename T>
void List<T>::PopFront() {
	if (IsEmpty()) {
		return;
	}

	Node<T>* next = this->head->Next;

	if (next != nullptr) {
		next->Prev = nullptr;
	}
	else {
		this->tail = nullptr;
	}

	delete this->head;
	this->head = next;
}

template <typename T>
bool List<T>::IsEmpty() {
	return this->head == nullptr;
}

template <typename T>
void List<T>::Clear() {
	while (!IsEmpty()) {
		PopFront();
	}
}

template <typename T>
void List<T>::Print() {
	Node<T>* it = this->head;

	while (it != nullptr) {
		cout << it->Data << endl;
		it = it->Next;
	}

	cout << endl;
}

template <typename T>
template <typename Func>
void List<T>::Sort(Func cmp) {
	if (IsEmpty() || this->head->Next == nullptr) {
		return;
	}

	bool swapped;
	Node<T>* temp;

	do {

		swapped = false;
		temp = this->head;

		while (temp->Next != nullptr) {
			if (cmp(temp->Data, temp->Next->Data)) {
				T t = temp->Data;
				temp->Data = temp->Next->Data;
				temp->Next->Data = t;
				swapped = true;
			}
			temp = temp->Next;
		}

	} while (swapped);
}

template <typename T>
List<T>::~List() {
	Clear();
}