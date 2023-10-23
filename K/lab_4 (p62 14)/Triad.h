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

		virtual Triad operator+(const Triad&);
		virtual Triad operator-(const Triad&);
		virtual Triad operator*(const Triad&);
		virtual Triad operator/(const Triad&);

		virtual Triad operator+(const int& n);
		virtual Triad operator-(const int& n);
		virtual Triad operator*(const int& n);
		virtual Triad operator/(const int& n);

		virtual Triad& operator++();
		virtual Triad& operator--();

		virtual Triad operator++(int);
		virtual Triad operator--(int);

		virtual bool operator>(const Triad&);
		virtual bool operator>=(const Triad&);

		virtual bool operator<(const Triad&);
		virtual bool operator<=(const Triad&);

		bool operator==(const Triad&);
		bool operator!=(const Triad&);

		virtual string ToString() const;

		friend istream& operator>>(istream&, Triad&);
		friend ostream& operator<<(ostream&, const Triad&);
};