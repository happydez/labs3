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

void Date::AddDays(int days) {
    Triad triad = Triad(n1, n2, n3 + days);
    Date newDate;
    newDate.addToDate(triad.First(), triad.Second(), triad.Third());
    n1 = newDate.First();
    n2 = newDate.Second();
    n3 = newDate.Third();
}

void Date::SubDays(int days) {
    Triad triad = Triad(n1, n2, n3 - days);
    Date newDate;
    newDate.addToDate(triad.First(), triad.Second(), triad.Third());
    n1 = newDate.First();
    n2 = newDate.Second();
    n3 = newDate.Third();
}

Date* Date::operator+(const Date& t) {
    Triad t1 = Triad(n1, n2, n3);
    Triad t2 = Triad(t.n1, t.n2, t.n3);
    auto t3 = t1 + t2;
    Date newDate = Date(t3->First(), t3->Second(), t3->Third());
    return new Date(newDate.n1, newDate.n2, newDate.n3);
}

Date* Date::operator-(const Date& t) {
    Triad t1 = Triad(n1, n2, n3);
    Triad t2 = Triad(t.n1, t.n2, t.n3);
    auto t3 = t1 - t2;
    Date newDate = Date(t3->First(), t3->Second(), t3->Third());
    return new Date(newDate.n1, newDate.n2, newDate.n3);
}

Date* Date::operator+(const int& i) {
    Triad triad = Triad(n1, n2, n3);
    auto newTriad = triad + i;
    Date newDate;
    newDate.addToDate(newTriad->First(), newTriad->Second(), newTriad->Third());
    return new Date(newDate.n1, newDate.n2, newDate.n3);
}

Date* Date::operator-(const int& i) {
    Triad triad = Triad(n1, n2, n3); 
    auto newTriad = triad - i;
    Date newDate;
    newDate.addToDate(newTriad->First(), newTriad->Second(), newTriad->Third());
    return new Date(newDate.n1, newDate.n2, newDate.n3);
}

Date& Date::operator++() {
    Triad t = Triad(n1, n2, n3);
    ++t;
    Date newDate = Date(t.First(), t.Second(), t.Third());
    return newDate;
}

Date& Date::operator--() {
    Triad t = Triad(n1, n2, n3);
    --t;
    Date newDate = Date(t.First(), t.Second(), t.Third());
    return newDate;
}

Date* Date::operator++(int) {
    Date temp = *this;
    Triad t = Triad(n1, n2, n3);
    t++;
    n1 = t.First();
    n2 = t.Second();
    n3 = t.Third();
    return new Date(temp.n1, temp.n2, temp.n3);
}

Date* Date::operator--(int) {
    Date temp = *this;
    Triad t = Triad(n1, n2, n3);
    t--;
    n1 = t.First();
    n2 = t.Second();
    n3 = t.Third();
    return new Date(temp.n1, temp.n2, temp.n3);
}

bool Date::operator>(const Date& t) {
    if (n1 < t.First()) {
        if (n2 < t.Second()) {
            if (n3 < t.Third()) {
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
    Triad t1 = Triad(n1, n2, n3);
    Triad t2 = Triad(d.n1, d.n2, d.n3);

    return t1 == t2;
}

bool Date::operator!=(const Date& d) {
    Triad t1 = Triad(n1, n2, n3);
    Triad t2 = Triad(d.n1, d.n2, d.n3);

    return !(t1 == t2);
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
    return out << date.ToString();
}