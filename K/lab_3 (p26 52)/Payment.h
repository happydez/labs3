#pragma once

#include <string>

#include "Date.h"

using std::string;

class Employee {
	private:
		string firstName;
		string middleName;
		string lastName;

	public:
		Employee();
		Employee(string firstName, string middleName, string lastName);

		string FirstName() const;
		string MiddleName() const;
		string LastName() const;

		string ToString() const;
};

class Payment {
	private:
		Employee employee;
		double salary; // оклад
		Date hireDate;
		double bonusPercent; // надбавки
		uint workedDays;
		uint totalWorkDays;
		double accruedSum; // начисления
		double withheldSum; // удержания

		void calculateAccruedSum();
		void calculateWithheldSum();

	public:
		Payment(Employee employee, double s, Date hireDate, double bp, uint wd, uint twd);

		double AccruedSum() const;
		double WithheldSum() const;
		double HandSum() const;

		DateTime WorkExperience() const;

		void PrintDetails() const;
};
