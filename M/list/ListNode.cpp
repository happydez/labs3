#include "ListNode.h"

Node::Node() {
	this->Data = int();
	this->Next = nullptr;
}

Node::Node(int data) {
	this->Data = data;
	this->Next = nullptr;
}

Node::~Node() {
	if (this != nullptr) delete this;
}