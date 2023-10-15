#include <iostream>

#include "Date.h"
#include "Payment.h"

using namespace std;

int main() {

	setlocale(0, "ru");

	auto employee = Payment(
		Employee("Иван", "Иванович", "Иванов"),
		72500.0,
		Date("2018.05.21"),
		5,
		21,
		30
	);

	employee.PrintDetails();

	return 0;
}