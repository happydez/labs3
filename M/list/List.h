#pragma once

#include "ListNode.h"

#include <iostream>
#include <vector>

using namespace std;

class List {
	private:
		Node* head;
		Node* tail;
	
	public:
		List();
		List(int data);
		List(vector<int> v);
		~List();

		bool IsEmpty();

		void Append(int data);
		void Prepend(int data);

		bool Remove(int data);

		Node* Iterator();
		Node* Find(int elem);

		void Print(string msg = "");
};