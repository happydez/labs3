#pragma once

#include "Triad.h"

class Date : public Triad {
	private:
		void normalize();
		void addToDate(int years, int months, int days);

	public:
		Date();
		Date(string date);
		Date(int years, int months, int days);

		static bool IsLeapYear(int year);
		static int DaysInMonth(int year, int month);

		Date AddDays(int days);
		Date SubDays(int days);

		Date* operator+(const Date& t);
		Date* operator-(const Date& t);

		Date& operator++();
		Date& operator--();

		Date operator++(int);
		Date operator--(int);

		bool operator>(const Date&);
		bool operator>=(const Date&);

		bool operator<(const Date&);
		bool operator<=(const Date&);

		bool operator==(const Date&);
		bool operator!=(const Date&);

		string ToString() const;

		friend istream& operator>>(istream& in, Date& date);
		friend ostream& operator<<(ostream& out, const Date& date);
};

