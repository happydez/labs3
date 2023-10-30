#pragma once

#include <iostream>

using namespace std;

class Array {
	protected:
		int cap;
		int size;
		int* data;

	public:
		Array();
		Array(int cap);
		~Array();

		int At(int index) const;
		int Count() const;
		int Search(int value) const;

		void Add(int value);
		void Remove(int value);

		virtual void Foreach() = 0;
		virtual void Addition(const Array& other) = 0;

		static void Sort(Array* array);
		static void Resize(Array* array, int newSize);
		static void Copy(Array* sourceArray, Array* destinationArray, int size);

		friend istream& operator>>(istream& in, Array& array);
		friend ostream& operator<<(ostream& out, const Array& array);
};

class SortArray : public Array {
	public:
		SortArray();
		SortArray(int cap);

		void Foreach() override;
		void Addition(const Array& other) override;
};

class XorArray : public Array {
public:
	XorArray();
	XorArray(int cap);

	void Foreach() override;
	void Addition(const Array& other) override;
};