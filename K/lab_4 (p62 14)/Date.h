#pragma once

#include "Triad.h"

class Date : public Triad {
	private:
		void addToDate(int years, int months, int days);

		Triad operator*(const Triad&);
		Triad operator/(const Triad&);
		Triad operator*(const int& n);
		Triad operator/(const int& n);

	public:
		Date();
		Date(string date);
		Date(const Triad& triad);
		Date(int years, int months, int days);

		static bool IsLeapYear(int year);
		static int DaysInMonth(int year, int month);

		void AddDays(int days);
		void SubDays(int days);

		Triad operator+(const Triad& t) override;
		Triad operator-(const Triad& t) override; 

		Triad operator+(const int& n) override;
		Triad operator-(const int& n) override;

		Triad& operator++() override;
		Triad& operator--() override;

		Triad operator++(int) override;
		Triad operator--(int) override;

		bool operator>(const Triad&) override;
		bool operator>=(const Triad&) override;

		bool operator<(const Triad&) override;
		bool operator<=(const Triad&) override;

		string ToString() const override;

		friend istream& operator>>(istream& in, Date& date);
		friend ostream& operator<<(ostream& out, const Date& date);
};

