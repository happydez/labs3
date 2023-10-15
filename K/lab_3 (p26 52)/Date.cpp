#include "Date.h"

#include <string>

using std::string;

DateTime::DateTime() {
	this->Day = this->Month = this->Year = 0;
}

DateTime::DateTime(uint day, uint month, uint year) {
	this->Day = day;
	this->Month = month;
	this->Year = year;
}

Date::Date() {
	this->dateTime = DateTime(0, 0, 0);
}

Date::Date(uint day, uint month, uint year) {
	this->dateTime = DateTime(day, month, year);
}

Date::Date(string date) {
	uint year = atoi(date.substr(0, 4).c_str());
	uint month = atoi(date.substr(5, 7).c_str());
	uint day = atoi(date.substr(8, 10).c_str());

	this->dateTime = DateTime(day, month, year);
}

Date::Date(DateTime dateTime) {
	this->dateTime = dateTime;
}

uint Date::Day() const {
	return this->dateTime.Day;
}

uint Date::Month() const {
	return this->dateTime.Month;
}

uint Date::Year() const {
	return this->dateTime.Year;
}

bool Date::IsLeapYear(uint year) {
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 != 0) return false;
	return true;
}

uint Date::daysInMonth() const {
	auto days = new int[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear(this->dateTime.Year) && this->dateTime.Month == 2) return 29;
	return days[this->dateTime.Month - 1];
}

void Date::Add(uint days) {
	this->dateTime.Day += days;
	while (this->dateTime.Day > daysInMonth()) {
		this->dateTime.Day -= daysInMonth();
		this->dateTime.Month++;
		if (this->dateTime.Month > 12) {
			this->dateTime.Month = 1;
			this->dateTime.Year++;
		}
	}
}

void Date::Sub(uint days) {
	while (days > 0) {
		if (days >= this->dateTime.Day) {
			days -= this->dateTime.Day;
			if (this->dateTime.Month == 1) {
				this->dateTime.Month = 12;
				this->dateTime.Year--;
			}
			else {
				this->dateTime.Month--;
			}
			this->dateTime.Day = daysInMonth();
		}
		else {
			this->dateTime.Day -= days;
			days = 0;
		}
	}
}

bool Date::Before(const Date& date) const {
	if (this->dateTime.Year != date.dateTime.Year) {
		return this->dateTime.Year < date.dateTime.Year;
	}
	else if (this->dateTime.Month != date.dateTime.Month) {
		return this->dateTime.Month < date.dateTime.Month;
	}
	else {
		return this->dateTime.Day < date.dateTime.Day;
	}
}

bool Date::After(const Date& date) const {
	if (this->dateTime.Year != date.dateTime.Year) {
		return this->dateTime.Year > date.dateTime.Year;
	}
	else if (this->dateTime.Month != date.dateTime.Month) {
		return this->dateTime.Month > date.dateTime.Month;
	}
	else {
		return this->dateTime.Day > date.dateTime.Day;
	}
}

bool Date::operator==(const Date& date) const {
	return (this->Year() == date.Year()) && (this->Month() == date.Month()) && (this->Day() == date.Day());
}

bool Date::operator!=(const Date& date) const {
	return !(*this == date);
}

Date Date::operator-(const Date& date) const {
	if (Before(date)) {
		return Date(0, 0, 0);
	}

	int d = this->Day() - date.Day();
	int m = this->Month() - date.Month();
	int y = this->Year() - date.Year();

	if (d < 0) {
		m--;
		d += Date(date.Day(), date.Month() - 1, date.Year()).daysInMonth();
	}

	if (m < 0) {
		y--;
		m += 12;
	}

	return Date(d, m, y);
}