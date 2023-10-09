#include "Money.h"

Money::Money() : _rubs(new long(0)), _kops(new byte(0)) {}

Money::Money(long rubs, byte kops) : _rubs(new long(rubs)), _kops(new byte(kops)) {
	if (kops >= 100 || kops <= -100) {
		throw std::out_of_range("kopecks must be in range [-99; 99]");
	}
}

Money::Money(const Money& m) {
	this->_rubs = new long(*m._rubs);
	this->_kops = new byte(*m._kops);
}

Money::~Money() {
	delete _rubs;
	delete _kops;
}

std::string Money::ToString() const {
	int temp = abs(*_kops);
	return std::to_string(*_rubs) + "," + (temp < 10 ? "0" + std::to_string(temp) : std::to_string(temp)) + " rub.";
}

Money Money::operator+(const Money& m) const {
	Money newM = Money(*this->_rubs + *m._rubs, 0);
	int temp = (int)*this->_kops + (int)*m._kops;
	if (temp >= 100) {
		*newM._rubs = *newM._rubs + temp / 100;
		*newM._kops = temp % 100;
	}
	else {
		*newM._kops = *this->_kops + *m._kops;
	}
	return newM;
}

Money Money::operator-(const Money& m) const {
	Money newM = Money(*this->_rubs - *m._rubs, 0);
	int temp = (int)*this->_kops - (int)*m._kops;
	if (temp < 0) {
		*newM._rubs = *newM._rubs + temp / 100;
		*newM._kops = temp % 100;
	}
	else {
		*newM._kops = *this->_kops - *m._kops;
	}
	return newM;
}

Money Money::operator*(int m) const {
	Money newM = Money(*this->_rubs * m, 0);
	int temp = (int)*this->_kops * m;
	*newM._rubs += temp / 100;
	*newM._kops += temp % 100;
	return newM;
}

Money Money::operator/(int m) const {
	Money newM = Money(*this->_rubs / m, 0);
	int temp = ((int)*this->_kops + ((*this->_rubs % m) * 100)) / m;
	*newM._kops = (temp < 0.01) ? 0 : temp;
	return newM;
}

Money Money::operator*(double m) const {
	int whole = (int)m;
	double real = m - (double)whole;
	Money newM = (*this * whole) * (real * 100) / 100;
	return newM;
}

//Money Money::operator/(double m) const {
//	int whole = (int)m;
//	double real = m - (double)whole;
//	Money newM = (*this / whole) / (real * 100) / 100;
//	return newM;
//}
//
//Money Money::operator/(double m) const {
//	Money newM = Money(*this->_rubs / m, 0);
//	int temp = (int)*this->_kops / m;
//	*newM._kops = (*this->_kops / m < 0.01) ? 0 : *this->_kops / m;
//	return newM;
//}

std::istream& operator >>(std::istream& in, Money& m) {
	long rubs; int kops;
	in >> rubs;
	in >> kops;

	if (kops >= 100 || kops <= -100) {
		throw std::out_of_range("kopecks must be in range [-99; 99]");
	}

	m._rubs = new long(rubs);
	m._kops = new byte(kops);
	return in;
}

std::ostream& operator <<(std::ostream& out, const Money& m) {
	out << m.ToString();
	return out;
}

bool Money::operator ==(const Money& other) const {
	return (this->_rubs == other._rubs) && (this->_kops == other._kops);
}

bool Money::operator !=(const Money& other) const {
	return !(*this == other);
}