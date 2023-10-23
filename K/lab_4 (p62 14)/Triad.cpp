#include "Triad.h"

Triad::Triad() {
	n1 = n2 = n3 = 0;
}

Triad::Triad(int n1, int n2, int n3) {
	this->n1 = n1;
	this->n2 = n2;
	this->n3 = n3;
}

int Triad::First() const {
	return n1;
}

int Triad::Second() const {
	return n2;
}

int Triad::Third() const {
	return n3;
}

string Triad::ToString() const {
	return std::to_string(n1) + " " + std::to_string(n2) + " " + std::to_string(n3);
}

Triad Triad::operator+(const Triad& t) {
	return Triad(n1 + t.n1, n2 + t.n2, n3 + t.n3);
}

Triad Triad::operator-(const Triad& t) {
	return Triad(n1 - t.n1, n2 - t.n2, n3 - t.n3);
}

Triad Triad::operator*(const Triad& t) {
	return Triad(n1 * t.n1, n2 * t.n2, n3 * t.n3);
}

Triad Triad::operator/(const Triad& t) {
	return Triad((t.n1 == 0) ? 0 : n1 / t.n1, (t.n2 == 0) ? 0 : n2 / t.n2, (t.n3 == 0) ? 0 : n3 / t.n3);
}

Triad Triad::operator+(const int& n) {
	return Triad(n1 + n, n2 + n, n3 + n);
}

Triad Triad::operator-(const int& n) {
	return Triad(n1 - n, n2 - n, n3 - n);
}

Triad Triad::operator*(const int& n) {
	return Triad(n1 * n, n2 * n, n3 * n);
}

Triad Triad::operator/(const int& n) {
	return Triad((n == 0) ? 0 : n1 / n, (n == 0) ? 0 : n2 / n, (n == 0) ? 0 : n3 / n);
}

Triad& Triad::operator++() {
	++n1; ++n2; ++n3;
	return *this;
}

Triad Triad::operator++(int) {
	Triad triad(n1, n2, n3);
	n1++; n2++; n3++;
	return triad;
}

Triad& Triad::operator--() {
	--n1; --n2; --n3;
	return *this;
}

Triad Triad::operator--(int) {
	Triad triad(n1, n2, n3);
	n1--; n2--; n3--;
	return triad;
}

bool Triad::operator==(const Triad& t) {
	return (n1 == t.n1) && (n2 == t.n2) && (n3 == t.n3);
}

bool Triad::operator!=(const Triad& t) {
	return !(*this == t);
}

bool Triad::operator>(const Triad& t) {
	return (n1 > t.n1) && (n2 > t.n2) && (n3 > t.n3);
}

bool Triad::operator>=(const Triad& t) {
	return (*this > t) ? true : (*this == t);
}

bool Triad::operator<(const Triad& t) {
	return (n1 < t.n1) && (n2 < t.n2) && (n3 < t.n3);
}

bool Triad::operator<=(const Triad& t) {
	return (*this < t) ? true : (*this == t);
}

istream& operator>>(istream& in, Triad& triad) {
	in >> triad.n1 >> triad.n2 >> triad.n3;
	return in;
}

ostream& operator<<(ostream& out, const Triad& triad) {
	out << triad.ToString();
	return out;
}