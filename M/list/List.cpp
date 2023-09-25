#include "List.h"

List::List() {
	this->head = nullptr;
	this->tail = nullptr;
}

List::List(vector<int> v) {
	for (auto e : v) {
		Append(e);
	}
}

List::List(int data) {
	this->head = new Node(data);
	this->tail = this->head;
}

List::~List() {
	Node* temp;
	while (this->head != nullptr) {
		temp = head->Next;
		delete head;
		head = temp;
	}
}

bool List::IsEmpty() {
	return this->head == nullptr;
}

void List::Append(int data) {
	if (IsEmpty()) {
		this->head = new Node(data);
		this->tail = this->head;
	}
	else {
		this->tail->Next = new Node(data);
		this->tail = this->tail->Next;
	}
}

void List::Prepend(int data) {
	if (IsEmpty()) {
		this->head = new Node(data);
		this->tail = this->head;
	}
	else {
		Node* newHead = new Node(data);
		newHead->Next = this->head;
		this->head = newHead;
	}
}

void List::Print(string msg) {
	if (IsEmpty()) return;

	if (msg != "") {
		cout << msg;
	}

	Node* temp = this->head;
	while (temp != nullptr) {
		cout << temp->Data << " ";
		temp = temp->Next;
	}

	cout << endl;
}

Node* List::Iterator() {
	return this->head;
}

Node* List::Find(int elem) {
	Node* result = nullptr;
	Node* it = this->head;

	while (it != nullptr) {
		if (it->Data == elem) {
			result = it;
			break;
		}
		it = it->Next;
	}

	return result;
}

bool List::Remove(int data) {
	if (IsEmpty()) return false;

	Node* it = this->head;

	if (it->Data == data) {
		this->head = this->head->Next;
		return true;
	}

	while (true) {
		if (it->Next == nullptr) {
			return false;
		}

		if (it->Next->Data == data) {
			it->Next = it->Next->Next;
			break;
		}

		it = it->Next;
	}

	it = nullptr;

	return true;
}

