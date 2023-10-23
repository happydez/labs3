#include "Date.h"

Date::Date() : Triad(0, 0, 0) {};

Date::Date(int year, int month, int day) : Triad(year, month, day) {};

Date::Date(string date) {
    n1 = atoi(date.substr(0, 4).c_str());
    n2 = atoi(date.substr(5, 7).c_str());
    n3 = atoi(date.substr(8, 10).c_str());
}

Date::Date(const Triad& triad) {
    n1 = triad.First();
    n2 = triad.Second();
    n3 = triad.Third();
}

int Date::DaysInMonth(int year, int month) {
	auto days = new int[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (IsLeapYear(year) && month == 2) return 29;
	return days[month - 1];
}

void Date::AddDays(int days) {
    addToDate(0, 0, days);
}

void Date::SubDays(int days) {
    addToDate(0, 0, -days);
}

Triad Date::operator+(const Triad& t) {
    Date newDate = Date(n1, n2, n3);
    newDate.addToDate(t.First(), t.Second(), t.Third());
    return newDate;
}

Triad Date::operator-(const Triad& t) {
    Date newDate = Date(n1, n2, n3);
    newDate.addToDate(-t.First(), -t.Second(), -t.Third());
    return newDate;
}

Triad Date::operator+(const int& i) {
    Date newDate = Date(n1, n2, n3);
    newDate.addToDate(i, i, i);
    return newDate;
}

Triad Date::operator-(const int& i) {
    Date newDate = Date(n1, n2, n3);
    newDate.addToDate(-i, -i, -i);
    return newDate;
}

Triad& Date::operator++() {
    this->addToDate(1, 1, 1);
    return *this;
}

Triad& Date::operator--() {
    this->addToDate(-1, -1, -1);
    return *this;
}

Triad Date::operator++(int) {
    Date temp = *this;
    this->addToDate(1, 1, 1);
    return static_cast<Triad>(temp);
}

Triad Date::operator--(int) {
    Date temp = *this;
    this->addToDate(-1, -1, -1);
    return static_cast<Triad>(temp);
}

bool Date::operator>(const Triad& t) {
    if (n1 < t.First()) {
        if (n2 < t.Second()) {
            if (n3 < t.Third()) {
                return false;
            }
        }
    }

    return true;
}

bool Date::operator>=(const Triad& t) {
    return (*this == t) || (*this > t);
}

bool Date::operator<(const Triad& t) {
    return !(*this >= t);
}

bool Date::operator<=(const Triad& t) {
    return (*this == t) || (*this < t);
}

bool Date::IsLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
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
    return out << static_cast<const Triad&>(date);
}