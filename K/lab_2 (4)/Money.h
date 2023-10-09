#pragma once

#include <string>
#include <istream>
#include <ostream>

typedef char byte;

typedef long* Rubles;
typedef byte* Kopecks;

class Money {
	private:
		Rubles _rubs;
		Kopecks _kops;
	
	public:
		Money();
		Money(long rubs, byte kops);
		Money(const Money& m);
		~Money();

		std::string ToString() const;

		bool operator==(const Money& other) const;
		bool operator!=(const Money& other) const;

		Money operator+(const Money& m) const;
		Money operator-(const Money& m) const;

		Money operator*(int m) const;
		Money operator/(int m) const;
		Money operator*(double m) const;
		Money operator/(double m) const;

		friend std::istream& operator >>(std::istream& in, Money& m);
		friend std::ostream& operator <<(std::ostream& out, const Money& m);
};