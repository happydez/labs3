#pragma once

template <typename T>
class Node {
	public:
		T Data;
		Node<T> *Next, *Prev;
		Node(T data);
};

template <typename T>
class List {
	private:
		Node<T> *head, *tail;

	public:
		List();
		~List();

		Node<T>* Iterator();
		Node<T>* PushBack(T data);
		void PopBack();
		Node<T>* PushFront(T data);
		void PopFront();
		
		void Print();
		void Clear();
		bool IsEmpty();

		template <typename Func>
		void Sort(Func cmp);
};