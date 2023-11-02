#include "Date.h"

Date::Date() : Triad(0, 0, 0) {};

Date::Date(int year, int month, int day) : Triad(year, month, day) {};

Date::Date(string date) {
    n1 = atoi(date.substr(0, 4).c_str());
    n2 = atoi(date.substr(5, 7).c_str());
    n3 = atoi(date.substr(8, 10).c_str());
}

int Date::DaysInMonth(int year, int month) {
	auto days = new int[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear(year) && month == 2) return 29;
	return days[month - 1];
}

Date Date::AddDays(int days) {
    Date newDate = Date(n1, n2, n3);
    newDate.addToDate(0, 0, days);
    return newDate;
}

Date Date::SubDays(int days) {
    Date newDate = Date(n1, n2, n3);
    newDate.addToDate(0, 0, -days);
    return newDate;
}

Date* Date::operator+(const Date& t) {
    Date* d = static_cast<Date*>(Triad::operator+(t));
    d->normalize();
    return d;
}

Date* Date::operator-(const Date& t) {
    Date* d = static_cast<Date*>(Triad::operator-(t));
    d->normalize();
    return d;
}

Date& Date::operator++() {
    Triad::operator++();
    return *this;
}

Date& Date::operator--() {
    Triad::operator--();
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    Triad::operator++(0);
    return temp;
}

Date Date::operator--(int) {
    Date temp = *this;
    Triad::operator--(0);
    return temp;
}

bool Date::operator>(const Date& t) {
    if (n1 < t.n1) {
        if (n2 < t.n2) {
            if (n3 < t.n3) {
                return false;
            }
        }
    }

    return true;
}

bool Date::operator>=(const Date& t) {
    return (*this == t) || (*this > t);
}

bool Date::operator<(const Date& t) {
    return !(*this >= t);
}

bool Date::operator<=(const Date& t) {
    return (*this == t) || (*this < t);
}

bool Date::operator==(const Date& d) {
    return Triad::operator==(d);
}

bool Date::operator!=(const Date& d) {
    return !(*this == d);
}

bool Date::IsLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void Date::normalize() {
    Date normalizedDate;
    normalizedDate.addToDate(n1, n2, n3);
    n1 = normalizedDate.n1;
    n2 = normalizedDate.n2;
    n3 = normalizedDate.n3;
}

void Date::addToDate(int years, int months, int days) {
    n1 += years; 
    n2 += months;

    while (n2 > 12) {
        n1++;
        n2 -= 12;
    }
    while (n2 < 1) {
        n1--;
        n2 += 12;
    }

    n3 += days;
    while (n3 > DaysInMonth(n1, n2)) {
        n3 -= DaysInMonth(n1, n2);
        n2++;
        if (n2 > 12) {
            n1++;
            n2 = 1;
        }
    }
    while (n3 < 1) {
        n2--;
        if (n2 < 1) {
            n1--;
            n2 = 12;
        }
        n3 += DaysInMonth(n1, n2);
    }
}

string Date::ToString() const {
    return std::to_string(n1) + ":" + (n2 >= 10 ? "" : "0") + std::to_string(n2) + ":" + (n3 >= 10 ? "" : "0") + std::to_string(n3);
}

istream& operator>>(istream& in, Date& date) {
    return in >> static_cast<Triad&>(date);
}

ostream& operator<<(ostream& out, const Date& date) {
    return out << date.ToString();
}