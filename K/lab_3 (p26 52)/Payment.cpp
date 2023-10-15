#define _CRT_SECURE_NO_WARNINGS

#include "Payment.h"

#include <iostream>
#include <chrono>
#include <ctime>

#include <iomanip>

Employee::Employee() {
	this->firstName = "";
	this->middleName = "";
	this->lastName = "";
}

Employee::Employee(string firstName, string middleName, string lastName) {
	this->firstName = firstName;
	this->middleName = middleName;
	this->lastName = lastName;
}

string Employee::FirstName() const {
	return this->firstName;
}

string Employee::MiddleName() const {
	return this->middleName;
}

string Employee::LastName() const {
	return this->lastName;
}

string Employee::ToString() const {
	return this->lastName + " " + this->firstName + " " + this->middleName;
}

Payment::Payment(Employee employee, double s, Date hireDate, double bp, uint wd, uint twd) {
	this->employee = employee;
	this->salary = s;
	this->hireDate = hireDate;
	this->bonusPercent = bp;
	this->workedDays = wd;
	this->totalWorkDays = twd;

	calculateAccruedSum();
	calculateWithheldSum();
}

void Payment::calculateAccruedSum() {
	double basic = (this->salary / this->totalWorkDays) * this->workedDays;
	double bonus = basic * (this->bonusPercent / 100.0);
	this->accruedSum = basic + bonus;
}

void Payment::calculateWithheldSum() {
	double pension = this->accruedSum * 0.01;
	double tax = this->accruedSum * 0.13;
	this->withheldSum = pension + tax;
}

double Payment::AccruedSum() const {
	return this->accruedSum;
}

double Payment::WithheldSum() const {
	return this->withheldSum;
}

double Payment::HandSum() const {
	return this->accruedSum - this->withheldSum;
}

DateTime Payment::WorkExperience() const {
	std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm* localTime = std::localtime(&currentTime);

	Date now = Date(localTime->tm_mday, 1 + localTime->tm_mon, 1900 + localTime->tm_year);
	Date sub = now - this->hireDate;

	return DateTime(sub.Day(), sub.Month(), sub.Year());
}

void Payment::PrintDetails() const {
	//std::cout << "Full Name: " << this->employee.ToString() << std::endl;
	//std::cout << "Accrued Amount: " << this->AccruedSum() << std::endl;
	//std::cout << "Withheld Amount: " << this->WithheldSum() << std::endl;
	//std::cout << "Amount to Hand: " << this->HandSum() << std::endl;
	// 
	//auto exp = this->WorkExperience();
	//std::cout << "Work Experience: " << exp.Day  << " days, " << exp.Month << " months, " << exp.Year << " years" << std::endl;

	const int width = 24;
	const int valueWidth = 28;

	std::cout << "+-------------------------+-----------------------------+" << std::endl;

	std::cout << "| " << std::setw(width) << "Полное имя:" << "| " << std::setw(valueWidth) << this->employee.ToString() << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "Зарплата:" << "| " << std::setw(valueWidth) << this->salary << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "Бонус (%):" << "| " << std::setw(valueWidth) << this->bonusPercent << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "Начисления:" << "| " << std::setw(valueWidth) << this->AccruedSum() << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "Удержания:" << "| " << std::setw(valueWidth) << this->WithheldSum() << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "ЗП на руки:" << "| " << std::setw(valueWidth) << this->HandSum() << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "Дней в текущем месяце:" << "| " << std::setw(valueWidth) << this->totalWorkDays << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;
	std::cout << "| " << std::setw(width) << "Проработаных дней:" << "| " << std::setw(valueWidth) << this->workedDays << "|" << std::endl;
	std::cout << "+-------------------------+-----------------------------+" << std::endl;

	auto exp = this->WorkExperience();
	std::string experience = std::to_string(exp.Day) + " дней, " + std::to_string(exp.Month) + " месяцев, " + std::to_string(exp.Year) + " лет";
	std::cout << "| " << std::setw(width) << "Опыт работы:" << "| " << std::setw(valueWidth) << experience << "|" << std::endl;

	std::cout << "+-------------------------+-----------------------------+" << std::endl;
}