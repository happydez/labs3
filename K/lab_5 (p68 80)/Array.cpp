#include "Array.h"

Array::Array() {
	this->cap = 0;
	this->size = 0;
	this->data = nullptr;
}

Array::Array(int cap) {
	this->cap = cap;
	this->size = 0;
	this->data = new int[cap];
};

Array::~Array() {
	delete[] data;
}

void Array::Sort(Array* array) {
	for (int i = 1; i < array->size; i++) {
		int j = i;
		while (j > 0 && (array->data[j] < array->data[j - 1])) {
			int temp = array->data[j];
			array->data[j] = array->data[j - 1];
			array->data[j - 1] = temp;
			j--;
		}
	}
}

void Array::Resize(Array* array, int newSize) {
	if (newSize < 0) {
		throw invalid_argument("newSize < 0");
	}

	Array* source = array;
	int* dest = new int[newSize];
	int elementsToCopy = min(array->size, newSize);
	for (int i = 0; i < elementsToCopy; i++) {
		dest[i] = source->data[i];
	}

	delete[] source->data;
	source->data = dest;
	source->size = min(source->size, newSize);
	source->cap = newSize;
}

void Array::Copy(Array* sourceArray, Array* destinationArray, int size) {
	if (sourceArray == nullptr) {
		throw invalid_argument("sourceArray is nullptr");
	}

	if (destinationArray == nullptr) {
		throw invalid_argument("destinationArray is nullptr");
	}

	if (sourceArray->size < size) {
		size = sourceArray->size;
	}

	for (int i = 0; i < destinationArray->size; i++) {
		if (i == size) {
			break;
		}

		destinationArray->data[i] = sourceArray->data[i];
	}
}

int Array::At(int index) const {
	if ((index >= 0) && (index < size)) {
		return data[index];
	}

	throw out_of_range("index out of array range");
}

int Array::Count() const {
	return size;
}

int Array::Search(int value) const {
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return i + 1;
		}
	}

	return -1;
}

void Array::Add(int value) {
	if (size == cap) {
		cap *= 2;
		Resize(this, cap);
	}

	data[size++] = value;
}

void Array::Remove(int value) {
	int index = Search(value);

	if (index == -1) {
		return;
	}

	int* newData = new int[size - 1];

	int q = 0;
	for (int i = 0; i < size; i++) {
		if (i != index - 1) {
			newData[q] = data[i];
			q++;
		}
	}

	delete[] data;

	data = newData;
	size = size - 1;
}

istream& operator>>(istream& in, Array& array) {
	if (array.size == 0) {
		throw invalid_argument("size == 0");
	}

	for (int i = 0; i < array.size; i++) {
		in >> array.data[i];
	}

	return in;
}

ostream& operator<<(ostream& out, const Array& array) {
	for (int i = 0; i < array.size; i++) {
		out << array.data[i] << " ";
	}

	out << endl;

	return out;
}


// SortArray

SortArray::SortArray() : Array() {}

SortArray::SortArray(int cap) : Array(cap) {}

void SortArray::Foreach() {
	Array::Sort(this);
}

void SortArray::Addition(const Array& other) {
	for (int i = 0; i < other.Count(); i++) {
		int temp = other.At(i);
		this->Add(temp);
	}
}

// XorArray

XorArray::XorArray() : Array() {}

XorArray::XorArray(int cap) : Array(cap) {}

void XorArray::Foreach() {
	for (int i = 0; i < size; i++) {
		data[i] = (int)sqrt((double)data[i]);
	}
}

void XorArray::Addition(const Array& other) {
	for (int i = 0; i < size; i++) {
		if (other.Count() > i) {
			data[i] = data[i] ^ other.At(i);
		}
	}

	int s = size;
	while (other.Count() > s) {
		this->Add(other.At(s));
		s++;
	}
}