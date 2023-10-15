#pragma once

#include <string>

using std::string;

typedef unsigned int uint;

struct DateTime {
	public:
		uint Day;
		uint Month;
		uint Year;

		DateTime();
		DateTime(uint day, uint month, uint year);
};

class Date {
	private:
		DateTime dateTime;

		uint daysInMonth() const;

	public:
		Date();
		Date(uint day, uint month, uint year);
		Date(string date);
		Date(DateTime dateTime);

		uint Day() const;
		uint Month() const;
		uint Year() const;

		void Add(uint days);
		void Sub(uint days);

		bool After(const Date& date) const;
		bool Before(const Date& date) const;

		bool operator==(const Date& date) const;
		bool operator!=(const Date& date) const;

		Date operator-(const Date& date) const;

		static bool IsLeapYear(uint year);
};
