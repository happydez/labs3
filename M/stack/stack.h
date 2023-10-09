#pragma once

class stack {
	private:
		int cap;
		char top;
		char* data;

		void resize();

	public:
		stack();
		stack(int capacity);

		bool is_empty();
		void push(char value);
		char peek();
		char pop();
		void clear();
		void print();
};