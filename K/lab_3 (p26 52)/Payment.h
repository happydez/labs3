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
		double salary; // �����
		Date hireDate;
		double bonusPercent; // ��������
		uint workedDays;
		uint totalWorkDays;
		double accruedSum; // ����������
		double withheldSum; // ���������

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
