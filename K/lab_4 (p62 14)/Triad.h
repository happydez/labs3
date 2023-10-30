#pragma once

#include <string>
#include <fstream>

using std::string;
using std::istream;
using std::ostream;

class Triad {
	protected:
		int n1, n2, n3;

	public:
		Triad();
		Triad(int, int, int);

		int First() const;
		int Second() const;
		int Third() const;

		Triad* operator+(const Triad&);
		Triad* operator-(const Triad&);
		Triad* operator*(const Triad&);
		Triad* operator/(const Triad&);
			 
		Triad* operator+(const int& n);
		Triad* operator-(const int& n);
		Triad* operator*(const int& n);
		Triad* operator/(const int& n);

		Triad& operator++();
		Triad& operator--();
		Triad* operator++(int);
		Triad* operator--(int);

		bool operator>(const Triad&);
		bool operator>=(const Triad&);
		bool operator<(const Triad&);
		bool operator<=(const Triad&);

		bool operator==(const Triad&);
		bool operator!=(const Triad&);

		string ToString() const;

		friend istream& operator>>(istream&, Triad&);
		friend ostream& operator<<(ostream&, const Triad&);
};