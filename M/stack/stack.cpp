#include "stack.h"

#include <iostream>

using namespace std;

stack::stack() {
	top = 0;
	cap = 4;
	data = new char[cap];
}

stack::stack(int capacity) {
	top = 0;
	cap = capacity;
	data = new char[capacity];
}

void stack::resize() {
	cap *= 2;
	auto newData = new char[cap];

	for (int i = 0; i < top; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

void stack::print() {
	for (int i = 0; i < top; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

bool stack::is_empty() {
	return top == 0;
}

void stack::push(char value) {
	if (top == cap) {
		resize();
	}

	data[top++] = value;
}

char stack::peek() {
	if (top == 0) {
		throw out_of_range("stack is empty");
	}

	return data[--top];
}

char stack::pop() {
	char vl = peek();
	return vl;
}

void stack::clear() {
	top = 0;
}